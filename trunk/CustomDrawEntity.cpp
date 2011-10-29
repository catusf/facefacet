// CustomDrawEntity.cpp: implementation of the CustomDrawEntity class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "CustomDrawEntity.h"

#include <rxobject.h>
#include <dbents.h>
#include <dbmain.h>
#include <acgi.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#ifdef CAD2000
ACRX_DXF_DEFINE_MEMBERS(CustomDrawEntity,AcDbEntity,	\
						AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,	\
						0,ASDK_CUSTOM_DRAW_ENTITY,Acgisamp);
#else
ACRX_DXF_DEFINE_MEMBERS(CustomDrawEntity,	\
						AcDbEntity,0,ASDK_CUSTOM_DRAW_ENTITY,Acgisamp);
#endif


CustomDrawEntity::CustomDrawEntity()
{
}

CustomDrawEntity::~CustomDrawEntity()
{
}

CustomDrawEntity::worldDraw(AcGiWorldDraw*	mode)
{
	ShellDataArray::iterator it;

	for (it=mpShellDataArray.begin(); it!=mpShellDataArray.end(); it++)
	{
		mode->geometry().shell( it->mpVertexList.size(),
			it->mpVertexList.begin(),
			it->mpFaceList.size(),
			it->mpFaceList.begin(),
			NULL,NULL,NULL);
	}

	return Adesk::kTrue;
}

Acad::ErrorStatus CustomDrawEntity::dwgInFields(AcDbDwgFiler* filer)
{
	assertWriteEnabled();

	Acad::ErrorStatus es;

	if ((es = AcDbEntity::dwgInFields(filer)) != Acad::eOk) {
		return es;
	}

	mpShellDataArray.dwgInFields(filer);

	return Acad::eOk;
}

Acad::ErrorStatus CustomDrawEntity::dwgOutFields(AcDbDwgFiler* filer) const
{

	assertReadEnabled();

	Acad::ErrorStatus es;

	if ((es = AcDbEntity::dwgOutFields(filer)) != Acad::eOk) 
	{
		return es;
	}

	mpShellDataArray.dwgOutFields(filer);

	return Acad::eOk;
}

Acad::ErrorStatus CustomDrawEntity::transformBy(const AcGeMatrix3d& xform)
{
	ShellDataArray::iterator it;
	int i, nSize;
	
	for (it=mpShellDataArray.begin(); it!=mpShellDataArray.end(); it++)
	{
		nSize = it->mpVertexList.size();
		
		for (i = 0; i < nSize; i++)
		{
			it->mpVertexList[i].transformBy(xform);
		}
	}
	
	return Acad::eOk;
}

ShellDataArray & CustomDrawEntity::shellDataArray()
{
	return mpShellDataArray;
}

ShellDataArray const & CustomDrawEntity::shellDataArray() const
{
	return mpShellDataArray;
}
