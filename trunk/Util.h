/*-----------------------------------------------
     File name    : Util.h
     Author       : 
  
     Description  : 
  -----------------------------------------------*/
#ifndef _UTIL_H
#define _UTIL_H

#include <adslib.h>
#include <dbsymtb.h>

Acad::ErrorStatus addToDatabase(AcDbEntity* pEnt, AcDbObjectId& objId);

Acad::ErrorStatus postToDatabase(AcDbEntity* pEnt, AcDbObjectId& objId);

Acad::ErrorStatus postToDatabase(AcDbEntity* pEnt);


#endif // _UTIL_H
