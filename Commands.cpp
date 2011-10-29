
#include "stdafx.h"

#include "Commands.h"
#include "adscodes.h"

#include "rxregsvc.h"
#include "aced.h"

#include <fstream>
#include <iomanip>

#include "SelectionUtil.h"
#include "geassign.h"
#include "dbpl.h"
#include "dbregion.h"
#include "dbents.h"
#include "dbsol3d.h"
#include "dbelipse.h"

#include "Util.h"

#include "CustomDrawEntity.h"
#include "CustomWorldDraw.h"


Command gCommand[] = 
{
	{"FacetFaces", "FF", "Facet face(s) of solid(s)", Commands::shadeFace},
	{"SetColorIndex", "SETCL", "Set color index of solid(s).", Commands::setColorIndex},
	{"SetDeviation", "SDEV", "Set deviation for faceting.", Commands::setFacetDeviation},
	{"CalcMassProp", "CMP", "Calculate mass properties.", Commands::calcMassProp},
	{"NewExtrude", "nex", "New Extrude command.", Commands::NewExtrude},
};

char * Command::m_sCommandGroup = "FF_COMMANDS";


// Register commands to exemplify the Autodesk Boundary
// Representation Library

int Commands::colorIndex = 1; // colorIndex set by user. Entity
// will shade itself in this color.

double Commands::deviation = 0.1; // Facet deviation. Smaller value
// causes more facets to be drawn and
// a more accurate represention of the
// geometry is obtained. This is set
// by the user.

void Commands::Register()
{
	int nCmds = sizeof(gCommand) / sizeof(Command);

	ads_printf("\nFF Commands:\n");
	for (int i = 0; i < nCmds; i++)
	{
		acedRegCmds->addCommand(Command::m_sCommandGroup,
			gCommand[i].m_sGlobalCmd,
			gCommand[i].m_sLocalCmd,
			ACRX_CMD_MODAL,
			gCommand[i].m_pFunctionCmd);

		ads_printf("\n%-8s: %s.", gCommand[i].m_sLocalCmd, gCommand[i].m_sDesc);
	}
	ads_printf("\n");
}

void Commands::UnRegister()
{
    // Un-register commands to test the Autodesk Boundary
	// Representation Library
	acedRegCmds->removeGroup( "FF_COMMANDS" );
}

bool GetNormal(AcDbEntity * pCurve, AcGeVector3d & normal)
{
	if (pCurve->isKindOf(AcDb2dPolyline::desc()))
	{
		normal = ((AcDb2dPolyline *)pCurve)->normal();
		return true;
	}
	else if (pCurve->isKindOf(AcDbCircle::desc()))
	{
		normal = ((AcDbCircle *)pCurve)->normal();
		return true;
	}
	else if (pCurve->isKindOf(AcDbEllipse::desc()))
	{
		normal = ((AcDbEllipse *)pCurve)->normal();
		return true;
	}
	else if (pCurve->isKindOf(AcDbPolyline::desc()))
	{
		normal = ((AcDbPolyline *)pCurve)->normal();
		return true;
	}
	
	return false;
}

void Commands::NewExtrude()
{
	AcDbObjectId id;

	if (!SelectionUtil::SelectSingle(id, KindOf(AcDbCurve::desc()), 
		"\nSelect a polyline object as profile (planar closed polyline, circle, or ellipse):"))
	{
		acutPrintf("\nFailed to select object.");
		return;
	}

	AcDbEntity*	pEntity = NULL;
	
	if (Acad::eOk!=acdbOpenAcDbEntity(pEntity, id, AcDb::kForRead))
	{
		acutPrintf("\nFailed to open profile object.");
		return;
	}

	AcGeVector3d normal;
	if (!GetNormal(pEntity, normal))
	{
		acutPrintf("\nNot a planar object. Cannot be used as profile.");
		pEntity->close();
		return;
	}

	AcGePoint3d center;
	
	if (RTNORM!=acedGetPoint(NULL, 
		"\nPick center point of profile: ", asDblArray(center)))
	{
		acutPrintf("\nFailed to pick the first point.");
		return;
	}

	while (true)
	{
		AcDbCurve * pPath = (AcDbCurve *)SelectionUtil::SelectSingle(KindOf(AcDbCurve::desc()), AcDb::kForRead,
			"\nSelect a curve object as path (line, arc, circle, ellipse, spline, or polyline):");
		
		if (!pPath)
		{
			acutPrintf("\nFailed to select object.");
			pEntity->close();
			return;
		}
		
		AcDbCurve * pNewEntity = (AcDbCurve*)pEntity->clone();
		
		pEntity->close();
		
		if (!pNewEntity)
		{
			acutPrintf("\nError to clone the selected object.");
			pPath->close();
			return;
		}
		
		AcDbObjectId newId;
		
		if (addToDatabase(pNewEntity, newId)!= Acad::eOk)
		{
			acutPrintf("\nFailed to add new cloned object to the drawing database.");
			
			pNewEntity->close();
			pPath->close();
			return;
		}
		
		AcGeVector3d path;
		AcGePoint3d start;
		double startParam;
		
		pPath->getStartParam(startParam);
		pPath->getFirstDeriv(startParam, path);
		pPath->getPointAtParam(startParam, start);
		
		AcGeMatrix3d mat, mat1;
		AcGeVector3d rotAxis = path.crossProduct(normal);
		mat1.setToRotation(-normal.angleTo(path), rotAxis, center);
		mat.setToTranslation(start - center);
		
		pNewEntity->transformBy(mat1);
		pNewEntity->transformBy(mat);
		
		pNewEntity->downgradeOpen();	//	from kForWrite to kForRead
		
		AcDbRegion * pRegion;
		
		AcDbVoidPtrArray curveSegments, regions;
		
		curveSegments.append(pNewEntity);
		
		if (Acad::eOk != AcDbRegion::createFromCurves(curveSegments, regions))
		{
			acutPrintf("\nFailed to create region from polyline.");
			pPath->close();
			pNewEntity->close();
			
			return;
		}
		
		AcDb3dSolid * pSolid;
		for (int i = 0; i < regions.length(); i++)
		{
			pRegion = (AcDbRegion*)regions[i];
			if (addToDatabase(pRegion, newId)!= Acad::eOk)
			{
				acutPrintf("\nFailed to add region object #%i to the drawing database.", i+1);
				continue;
			}
			
			pSolid = new AcDb3dSolid;
			
			if (Acad::eOk!=pSolid->extrudeAlongPath(pRegion, pPath))
			{
				acutPrintf("\nFailed to create extruded object #%i.", i+1);
				pRegion->close();
				continue;
			}
			else
			{
				pRegion->upgradeOpen();
				pRegion->erase();
				pRegion->close();
				
				if (addToDatabase(pSolid, newId)!= Acad::eOk)
				{
					acutPrintf("\nFailed to add solid object #%i to the drawing database.", i+1);
					continue;
				}
				
				pSolid->close();
			}
		}
		
		pPath->close();
		pNewEntity->upgradeOpen();
		pNewEntity->erase();
		pNewEntity->close();
	}
}


void Commands::setColorIndex()
{
	// Function will obtain a color index from the user. Checks
	// if the index has a valid value.

	int colorInd = colorIndex;
	char	prompt[300];
	sprintf(prompt,"\nEnter color index[%d]: ",colorIndex);

	switch (ads_getint(prompt, &colorInd)) {

	case RTNORM:
		if (colorInd < 1 || colorInd > 256)
			ads_printf("\nColor index must be between 1-256");
		else
			colorIndex = colorInd;
		break;

	default:
		break;
	}
}

void Commands::setFacetDeviation()
{
	// Function will obtain the desired facet deviation from the user.
	// Restricts the user to entering a deviation between 0.005 and 0.1

	double facetDev = deviation;

	char prompt[300];
	sprintf(prompt,"\nEnter facet deviation[%f]: ",deviation);

	switch (ads_getreal(prompt, &facetDev)) {

	case RTNORM:
		deviation = facetDev;
		break;

	default:
		break;
	}
}

void Commands::calcMassProp()
{
	AcDbObjectIdArray ids;

	if (SelectionUtil::SelectMultiple(ids))
	{
		AcDbEntity*	pEntity = NULL;
		AcDb3dSolid* pSolid;

		int nLength = ids.length();
		double dVolume, dComVolume = 0.0;
		AcGePoint3d centroid, comCentroid;
		double dMomInertia[3];
		double dProdInertia[3];
		double dPrinMoments[3];
		AcGeVector3d prinAxes[3];
		double dRadiiGyration[3];
		AcDbExtents extents;

		AcDbPoint *pPoint;
		int nCount = 0;

		for (int i = 0; i < nLength; i++)
		{
			if (Acad::eOk!=acdbOpenAcDbEntity(pEntity, ids[i], AcDb::kForRead))
			{
				ads_printf("\nError open object.");
				continue;
			}

			if (!pEntity->isKindOf(AcDb3dSolid::desc()))
			{
				ads_printf("\nNot a 3D solid. Entity #%i", i+1);
				continue;
			}

			pSolid = (AcDb3dSolid*) pEntity;

			if (Acad::eOk!=pSolid->getMassProp(
				dVolume,
				centroid,
				dMomInertia,
				dProdInertia,
				dPrinMoments,
				prinAxes,
				dRadiiGyration,
				extents))
			{
				ads_printf("\nError get mass properties. Solid #%i", i+1);
				continue;
			}
			pEntity->close();

			pPoint = new AcDbPoint(centroid);
			pPoint->setColorIndex(2);

			if (Acad::eOk!=postToDatabase(pPoint))
			{
				ads_printf("\nCannot create point at centroid of solid #%i.", i+1);
			}

			pPoint->close();

			nCount++;
			dComVolume+=dVolume;
			comCentroid+=centroid.asVector()*dVolume;

			ads_printf("\nSolid #%i:", nCount);
			ads_printf("\n\tVolume: %.4f", dVolume);
			ads_printf("\n\tCentroid: (%.4f,%.4f,%.4f)", centroid[0], centroid[1], centroid[2]);
			ads_printf("\n\tRadii of Gyration: (%.4f,%.4f,%.4f)", dRadiiGyration[0], dRadiiGyration[1], dRadiiGyration[2]);

			// Call the entity's worldDraw with CustomWorldDraw
		}

		comCentroid[0] /= dComVolume;
		comCentroid[1] /= dComVolume;
		comCentroid[2] /= dComVolume;

		ads_printf("\n");
		ads_printf("\nTotal %i solid(s):", nCount);
		ads_printf("\n\tVolume: %.4f", dComVolume);
		ads_printf("\n\tCentroid: (%.4f,%.4f,%.4f)", comCentroid[0], comCentroid[1], comCentroid[2]);

		pPoint = new AcDbPoint(comCentroid);
		pPoint->setColorIndex(1);

		if (Acad::eOk!=postToDatabase(pPoint))
		{
			ads_printf("\nCannot create point at centroid of the system of solid.", i+1);
		}
		pPoint->close();
	}
}

// Function will allow user to select faces of solids or regions.
// It will then facet the entity and create a custom entity to
// display the facets.
void Commands::shadeFace()
{
	AcDbObjectIdArray ids;

	if (SelectionUtil::SelectMultiple(ids))
	{
		AcDbEntity*	pEntity = NULL;

		CustomWorldDraw	*pMyWorldDraw = new CustomWorldDraw;

		// Set the facet deviation value
//		pMyWorldDraw->setDeviation(deviation);

		int i,
			nLength = ids.length();
		for (i = 0; i < nLength; i++)
		{
			if (Acad::eOk!=acdbOpenAcDbEntity(pEntity, ids[i], AcDb::kForRead))
			{
				ads_printf("\nError open object #%i.", i+1);
				continue;
			}

			acutPrintf("\nObject name: %s", pEntity->desc()->name());

			// Call the entity's worldDraw with CustomWorldDraw
			pEntity->worldDraw(pMyWorldDraw);

			pEntity->close();
		}

		//	Create custom entity
		CustomDrawEntity*	pCustEntity = new CustomDrawEntity;
		pCustEntity->shellDataArray() = pMyWorldDraw->shellDataArray();

		AcDbObjectId	custOID;
		postToDatabase(pCustEntity, custOID);

		char sFileName[100];

		if (RTNORM!=ads_getstring(true, "\nFile name (without .bdf): ", sFileName))
			return;
		
		strcat(sFileName, ".bdf");
		
		std::ofstream of(sFileName);

		pMyWorldDraw->WriteText(of);

		delete pMyWorldDraw; // delete the worldDraw object
	}

	return;

	/*	if (RTNORM!=ads_getstring(true, "\nFile name: ", sFileName))
	return;

	 strcat(sFileName, ".bdf");
	*/
#ifdef TESTTEST
	if (ads_entsel("\nSelect object", entname, pt) != RTNORM)
	{
		return;
	}

	objId.setFromOldId(entname[0]);
	AcDbEntity*	pEntity = NULL;
	acdbOpenAcDbEntity(pEntity, objId, AcDb::kForRead);

	if(NULL != pEntity)
	{
		CustomWorldDraw	*pMyWorldDraw = new CustomWorldDraw;

		// Set the facet deviation value
		pMyWorldDraw->setDeviation(deviation);

		// Call the entity's worldDraw with CustomWorldDraw
		pEntity->worldDraw(pMyWorldDraw);

		pEntity->close();
		*/
		/* CustomDrawEntity*	pCustEntity = new CustomDrawEntity;
		// Obtain pointer to ShellData from pMyWorldDraw and assign
		// it to the CustomEntity which will draw facets on the screen
		pCustEntity->mpShellDataArray = pMyWorldDraw->shellDataArray();

		 std::ofstream of(sFileName);
		 // std::ofstream of1("c:/test.dat");

			pMyWorldDraw->WriteText(of);
			// pMyWorldDraw->WriteBinary(of1);

			 AcDbObjectId	custOID;
			 postToDatabase(pCustEntity, custOID);
			 */
			 // delete pMyWorldDraw; // delete the worldDraw object
	}
#endif TESTTEST
}
