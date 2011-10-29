// CustomWorldGeometry.cpp: implementation of the CustomWorldGeometry class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "CustomWorldGeometry.h"
#include "CustomWorldDraw.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Implementation of CustomWorldGeometry

ACRX_DEFINE_MEMBERS(CustomWorldGeometry);
CustomWorldGeometry::CustomWorldGeometry(CustomWorldDraw* pWorldDraw)
{
	mpCustomWorldDraw = pWorldDraw; // store a back pointer to worldDraw object that instantiates
	// this worldGeometry object.
}

CustomWorldGeometry::~CustomWorldGeometry()
{
}

void CustomWorldGeometry::getModelToWorldTransform(AcGeMatrix3d &pMatrix) const
{
	return;
}
void CustomWorldGeometry::getWorldToModelTransform(AcGeMatrix3d &pMatrix) const
{
	return;
}
void CustomWorldGeometry::setExtents(AcGePoint3d *pNewExtents) const
{
	return;
}

Adesk::Boolean CustomWorldGeometry::circle(const AcGePoint3d& center,
										   const double radius,
										   const AcGeVector3d& normal
										   ) const
{
	ads_printf("\na circle");
	
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::circle(const AcGePoint3d& pt1,
										   const AcGePoint3d& pt2,
										   const AcGePoint3d& pt3
										   ) const
{
	ads_printf("\na circle");
	
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::circularArc(const AcGePoint3d& center,
												const double radius,
												const AcGeVector3d& normal,
												const AcGeVector3d& startVector,
												const double sweepAngle,
												const AcGiArcType arcType
												) const
{
	ads_printf("\na circularArc");
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::circularArc(const AcGePoint3d& start,
												const AcGePoint3d& point,
												const AcGePoint3d& end,
												const AcGiArcType arcType
												) const
{
	ads_printf("\na circularArc");
	return Adesk::kFalse;
}
/*
Adesk::Boolean CustomWorldGeometry::polyline(const Adesk::UInt32 nbPoints,
											 const AcGePoint3d* pVertexList,
											 const AcGeVector3d* pNormal) const
{
	ads_printf("\na polyline");
	return Adesk::kFalse;
}
*/
Adesk::Boolean CustomWorldGeometry::polygon(const Adesk::UInt32 nbPoints,
											const AcGePoint3d* pVertexList
											) const
{
	ads_printf("\na polygon");
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::mesh(const Adesk::UInt32 rows,
										 const Adesk::UInt32 columns,
										 const AcGePoint3d* pVertexList,
										 const AcGiEdgeData* pEdgeData,
										 const AcGiFaceData* pFaceData,
										 const AcGiVertexData* pVertexData
										 ) const
{
	//	ads_printf("\na shell");
	ShellData shellData;

	int nbVertex = rows*columns;
	
/*	acutPrintf("\nrows: %i, cols: %i", rows, columns);
	acutPrintf("\nnVertex: %i", nbVertex);
*/
	shellData.mpVertexList.resize(nbVertex); // Add number of vertices to ShellData
	
	std::copy(pVertexList, pVertexList+nbVertex, shellData.mpVertexList.begin());
	
	int nFaces = (rows - 1)* (columns - 1);
//	acutPrintf("\nnFaces: %i", nFaces);

	//	Each face needs 5 int: 1 for size, 4 for vertices
	Adesk::UInt32 faceListSize = 5 * nFaces;
	
	shellData.mpFaceList.resize(faceListSize);

//	acutPrintf("\nFaces: ");
	int c = columns - 1,
		k;
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < columns - 1; j++)
		{
			k = i*c + j;

			shellData.mpFaceList[5*k + 0] = 4;
			shellData.mpFaceList[5*k + 1] = (i + 0) * columns + j + 0;
			shellData.mpFaceList[5*k + 2] = (i + 0) * columns + j + 1;
			shellData.mpFaceList[5*k + 3] = (i + 1) * columns + j + 1;
			shellData.mpFaceList[5*k + 4] = (i + 1) * columns + j + 0;

/*			acutPrintf("\nFace %i: ", k);
			acutPrintf("%i - %i - %i - %i: ", 
				shellData.mpFaceList[5*k + 1], 
				shellData.mpFaceList[5*k + 2],
				shellData.mpFaceList[5*k + 3],
				shellData.mpFaceList[5*k + 4]);
*/		}
	}

//	std::copy(pFaceList, pFaceList+faceListSize, shellData.mpFaceList.begin());
	
	mpCustomWorldDraw->shellDataArray().push_back(shellData);
	mpCustomWorldDraw->Colors().push_back(mpCustomWorldDraw->mpSubEntityTraits->color());
	
	return Adesk::kFalse;
}


Adesk::Boolean CustomWorldGeometry::shell(const Adesk::UInt32 nbVertex,
										  const AcGePoint3d* pVertexList,
										  const Adesk::UInt32 faceListSize,
										  const Adesk::Int32* pFaceList,
										  const AcGiEdgeData* pEdgeData,
										  const AcGiFaceData* pFaceData,
										  const AcGiVertexData* pVertexData,
										  const struct resbuf* pResBuf
										  ) const
										  
{
	//	ads_printf("\na shell");
	ShellData shellData;
	
	shellData.mpVertexList.resize(nbVertex); // Add number of vertices to ShellData
	
	std::copy(pVertexList, pVertexList+nbVertex, shellData.mpVertexList.begin());
	
	shellData.mpFaceList.resize(faceListSize);
	std::copy(pFaceList, pFaceList+faceListSize, shellData.mpFaceList.begin());
	
	mpCustomWorldDraw->shellDataArray().push_back(shellData);
	mpCustomWorldDraw->Colors().push_back(mpCustomWorldDraw->mpSubEntityTraits->color());
	
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::text(const AcGePoint3d& position,
										 const AcGeVector3d& normal,
										 const AcGeVector3d& direction,
										 const double height,
										 const double width,
										 const double oblique,
										 const char* pMsg
										 ) const
{
	ads_printf("\na text");
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::text(const AcGePoint3d& position,
										 const AcGeVector3d& normal,
										 const AcGeVector3d& direction,
										 const char* pMsg,
										 const Adesk::Int32 length,
										 const Adesk::Boolean raw,
										 const AcGiTextStyle &pTextStyle
										 ) const
{
	ads_printf("\na text");
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::xline(const AcGePoint3d& one_xline_point,
										  const AcGePoint3d& a_different_xline_point
										  ) const
{
	ads_printf("\na xline");
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::pline(const AcDbPolyline& lwBuf,
										  Adesk::UInt32 fromIndex,
										  Adesk::UInt32 numSegs
										  ) const
{
	ads_printf("\na pline");
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::ray(const AcGePoint3d& rays_starting_point,
										const AcGePoint3d& a_different_ray_point
										) const
{
	ads_printf("\na ray");
	return Adesk::kFalse;
}

Adesk::Boolean  CustomWorldGeometry::pushClipBoundary(AcGiClipBoundary * pBoundary)
{
	ads_printf("\nCustomWorldGeometry::pushClipBoundary");
	return Adesk::kFalse;
}

void            CustomWorldGeometry::popClipBoundary()
{
	ads_printf("\nCustomWorldGeometry::popClipBoundary");
}


Adesk::Boolean  CustomWorldGeometry::draw(AcGiDrawable*) const
{
	ads_printf("\nCustomWorldGeometry::draw");
	return Adesk::kFalse;
}

Adesk::Boolean  CustomWorldGeometry::polyline(const Adesk::UInt32 nbPoints,
                         const AcGePoint3d* pVertexList,
				   const AcGeVector3d* pNormal,
				   Adesk::Int32 lBaseSubEntMarker) const
{
	ads_printf("\nCustomWorldGeometry::polyline");
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::pushModelTransform(const AcGeVector3d & vNormal)
{
	ads_printf("\nCustomWorldGeometry::pushModelTransfrom (vec)");
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::pushModelTransform(const AcGeMatrix3d & xMat)
{
	ads_printf("\nCustomWorldGeometry::pushModelTransfrom (mat)");
	return Adesk::kFalse;
}

Adesk::Boolean CustomWorldGeometry::popModelTransform()
{
	ads_printf("\nCustomWorldGeometry::popModelTransform");
	return Adesk::kFalse;
}

