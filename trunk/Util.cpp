
#include "stdafx.h"

#include "Util.h"

#include <dbapserv.h>
#include <migrtion.h>

//// SOME SUPPORT FUNCTIONS
Acad::ErrorStatus getSubEntPtr(AcDbObjectId& objId);

// Add the given entity to the current Database
Acad::ErrorStatus
addToDatabase(AcDbEntity* pEnt, AcDbObjectId& objId)

{
    Acad::ErrorStatus acadReturnValue = Acad::eOk;
    AcDbBlockTable* pBlockTable;
    AcDbBlockTableRecord* pSpaceRecord;
	
	AcDbDatabase *pCurDwg = acdbHostApplicationServices()->workingDatabase();
    if (pCurDwg == NULL)
        return Acad::eNoDatabase;
	
    if ((acadReturnValue = pCurDwg->getBlockTable(pBlockTable,
        AcDb::kForRead)) != Acad::eOk) 
	{
        acutPrintf("\n acdbCurDwg()->getBlockTable() failed");
        return acadReturnValue;
    }
	
    if ((acadReturnValue = pBlockTable->getAt(ACDB_MODEL_SPACE, 
        pSpaceRecord, AcDb::kForWrite)) != Acad::eOk) 
	{
        acutPrintf("\n AcDbBlockTable::getAt() failed");
        return acadReturnValue;
    }
	
    // close the block table object
    if ((acadReturnValue = pBlockTable->close()) != Acad::eOk) 
	{
        acutPrintf("\n AcDbBlockTable::close() failed");
        return acadReturnValue;
    }
	
    // append the entity to the display list
    if ((acadReturnValue = pSpaceRecord->appendAcDbEntity(objId, pEnt))
        != Acad::eOk) 
	{
        acutPrintf("\n AcDbBlockTableRecord::appendAcDbEntity() failed");
        return acadReturnValue;
    }
	
    // close the block table record object
    if ((acadReturnValue = pSpaceRecord->close()) != Acad::eOk) 
	{
        acutPrintf("\n AcDbBlockTableRecord::close() failed");
        return acadReturnValue;
    }
	
    return acadReturnValue;
}

Acad::ErrorStatus postToDatabase(AcDbEntity* pEnt, AcDbObjectId& objId)
{
	// Given an entity, this function will post it to the database
	// in MODEL_SPACE and then return the objectId; returns eOk if
	// all went well.

	Acad::ErrorStatus es;
	AcDbBlockTable* pBlockTable;
	AcDbBlockTableRecord* pSpaceRecord;

	es = acdbCurDwg()->getBlockTable(pBlockTable, AcDb::kForRead);
	assert(es == Acad::eOk);

	es = pBlockTable->getAt(ACDB_MODEL_SPACE, pSpaceRecord, AcDb::kForWrite);
	assert(es == Acad::eOk);

	es = pBlockTable->close();
	assert(es == Acad::eOk);

	es = pSpaceRecord->appendAcDbEntity(objId, pEnt);
	assert(es == Acad::eOk);

	es = pEnt->close();
	assert(es == Acad::eOk);

	es = pSpaceRecord->close();
	assert(es == Acad::eOk);

	return es;
}

Acad::ErrorStatus postToDatabase(AcDbEntity* pEnt)
{
	AcDbObjectId id;
	return postToDatabase(pEnt, id);
}
