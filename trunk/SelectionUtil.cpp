// SelectionUtil.cpp: implementation of the SelectionUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include <geassign.h>
#include <adslib.h>
#include <dbsymtb.h>

#ifdef CAD2000
#include <migrtion.h>
#include <dbapserv.h>
#endif CAD2000

#include "SelectionUtil.h"
#include <string.h>
#include <stdio.h>


//////////////////////////////////////////////////////////////////////

//_HDAI_BEGIN

const char * SelectionUtil::None="";

const char * SelectionUtil::Last="L";

const char * SelectionUtil::Previous="P";

const char * SelectionUtil::Implied="I";

const char * SelectionUtil::Window="W";

const char * SelectionUtil::Crossing="C";

const char * SelectionUtil::Fence="F";

const char * SelectionUtil::CrossPoly="CP";

const char * SelectionUtil::WinPoly="WP";

const char * SelectionUtil::Filter="X";

const char * SelectionUtil::Single="S";

const char * SelectionUtil::SsSingle = ":S";

//////////////////////////////////////////////////////////////////////

void SelectionUtil::UnHighLight(const AcDbObjectId & id)
{
	AcDbEntity *pEnt;
	if(acdbOpenObject(pEnt,id,AcDb::kForRead)==Acad::eOk)
	{
		pEnt->unhighlight();
		pEnt->close();
	}
}

void SelectionUtil::UnHighLight(const AcDbObjectIdArray & ids)
{
	AcDbEntity *pEnt;
	int i,
		nLength = ids.length();

	for (i = 0; i < nLength; i++)
	{
		if(acdbOpenObject(pEnt,ids[i],AcDb::kForRead)==Acad::eOk)
		{
			pEnt->unhighlight();
			pEnt->close();
		}
	}
}

void SelectionUtil::HighLight(const AcDbObjectId & id)
{
	AcDbEntity *pEnt;
	if(acdbOpenObject(pEnt,id,AcDb::kForRead)==Acad::eOk)
	{
		pEnt->close();
		pEnt->highlight();
	}
}

AcDbEntity * SelectionUtil::SelectSingle(EntityCondition const & cond,
										 AcDb::OpenMode const & kMode,
										 char const * sPrompt,
										 bool bHightLight)
										 //
										 //	Select mét ®èi t­îng trong b¶n vÏ AutoCAD
										 //	Cho tr­íc lo¹i ®èi t­îng (class name), dßng nh¾c
										 //	Tr¶ vÒ con trá tíi object
										 //	M· tr¶ vÒ 0 lµ tèt, kh¸c 0 lµ lçi
{
	ads_name entName;
	AcDbEntity * pEnt = NULL;
	char const * sThePrompt = sPrompt==NULL ? "\nSelect object: ": sPrompt;
	AcGePoint3d pickPoint;

	if (ads_entsel(sThePrompt, entName, asDblArray(pickPoint))!=RTNORM)
		return NULL;	//	khong chon doi tuong

	AcDbObjectId objId;

	if (Acad::eOk!=acdbGetObjectId(objId, entName))
		return NULL;

	if (Acad::eOk!=acdbOpenObject(pEnt, objId, AcDb::kForRead))
		return NULL;

	if (cond(pEnt))
	{
		if (bHightLight)
			pEnt->highlight();

		if (kMode==AcDb::kForWrite)
			pEnt->upgradeOpen();

		return pEnt;
	}

	pEnt->close();

	return NULL;
}

bool SelectionUtil::SelectSingle(AcDbObjectId &objId,
								 EntityCondition const & cond,
								 char const * sPrompt,
								 bool bHightLight)
{
	objId = AcDbObjectId::kNull;

	ads_name entName;
	AcDbEntity * pEnt = NULL;
	char const * sThePrompt = sPrompt==NULL ? "\nSelect object: ": sPrompt;
	AcGePoint3d pickPoint;

	if (ads_entsel(sThePrompt, entName, asDblArray(pickPoint))!=RTNORM)
		return false;	//	khong chon doi tuong

	if (Acad::eOk!=acdbGetObjectId(objId, entName))
		return false;

	if (Acad::eOk!=acdbOpenObject(pEnt, objId, AcDb::kForRead))
		return false;

	if (cond(pEnt))
	{
		if (bHightLight)
			pEnt->highlight();

		pEnt->close();

		return true;
	}

	pEnt->close();

	return false;
}

bool SelectionUtil::SelectX(AcDbObjectIdArray &idArray,
							EntityCondition const & cond,
							bool bRemoveAll)
{
	if (bRemoveAll)
		idArray.setLogicalLength(0);

	AcDbBlockTable *pBlkTbl;
	acdbCurDwg()->getBlockTable(pBlkTbl, AcDb::kForRead);

	AcDbBlockTableRecord *pBlkTblRcd;
	pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRcd,
		AcDb::kForRead);
	pBlkTbl->close();

	AcDbBlockTableRecordIterator *pBlkTblRcdItr;
	pBlkTblRcd->newIterator(pBlkTblRcdItr);

	AcDbEntity *pEnt;
	for (pBlkTblRcdItr->start(); !pBlkTblRcdItr->done(); pBlkTblRcdItr->step())
	{
		pBlkTblRcdItr->getEntity(pEnt, AcDb::kForRead);

		if (cond(pEnt))
			idArray.append(pEnt->objectId());

		pEnt->close();
	}

	pBlkTblRcd->close();
	delete pBlkTblRcdItr;

	return true;
}

int SelectionUtil::SelectMultiple(AcDbObjectIdArray & idArray,
								 EntityCondition const & cond,
								 char const * selectPrompt,
								 char const * removePrompt,
								 bool bHightLight)
								 //	Hµm chän ®èi t­îng dùa trªn c¸c ®iÒu kiÖn hiÖn cã
{
	idArray.setLogicalLength(0);
	ads_name ssname, ename;

	const char * prompt[2];
	selectPrompt ? prompt[0] = selectPrompt: prompt[0] = "Select object(s):";
	removePrompt ? prompt[1] = removePrompt: prompt[1] = "Remove object(s):";

	//	stat=ads_ssget(type + ":$",prompt,NULL,passFilter,ssName);

	if (RTNORM!=ads_ssget(":$", prompt, NULL, NULL, ssname))
		return 0;

	long nLength;
	ads_sslength(ssname, &nLength);

	AcDbObjectId objId;
	AcDbEntity * pEntity;

	for (int i = 0; i < nLength; i++)
	{
		ads_ssname(ssname, i, ename);
		acdbGetObjectId(objId, ename);

		if (Acad::eOk!=acdbOpenObject(pEntity, objId, AcDb::kForRead))
			continue;

		if (cond(pEntity))
		{
			idArray.append(objId);

			if (bHightLight)
				pEntity->highlight();
		}

		pEntity->close();
	}

	ads_ssfree(ssname);

	return idArray.length();
}

//_HDAI_END
