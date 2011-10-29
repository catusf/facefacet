// SelectionUtil.h: interface for the SelectionUtil class.
//
//	L�p c�c ti�n �ch ch�n ��i t��ng
//
//////////////////////////////////////////////////////////////////////

#ifndef __SELECTIONUTIL_H__
#define __SELECTIONUTIL_H__

//#include <Hdai/HdaiDef.h>
//#include <Hdai/EntityFunctionObject.h>
#include "EntityFunctionObject.h"

#include <dbmain.h>


//_HDAI_BEGIN

struct SelectionUtil
{
	//////////////////////////////////////////////////////////////////////
	//	C�c ki�u select ��i t��ng
	//	Xem cuon Customization Guide, trang 251

	static const char * None;

	static const char * Last;

	static const char * Previous;

	static const char * Implied;

	static const char * Window;

	static const char * Crossing;

	static const char * Fence;

	static const char * CrossPoly;

	static const char * WinPoly;

	static const char * Filter;

	static const char * Single;

	static const char * SsSingle;	//	":S" mode

	//////////////////////////////////////////////////////////////////////

	static bool SelectSingle(AcDbObjectId &objId,
		EntityCondition const & cond,
		char const * sPrompt = NULL,
		bool bHightLight = false);
	//
	//	Select m�t ��i t��ng trong b�n v� AutoCAD
	//	Cho tr��c lo�i ��i t��ng (class name), d�ng nh�c
	//	Tr� v� object id c�a ��i t��ng
	//	M� tr� v� true l� t�t, kh�c false l� l�i

	static AcDbEntity * SelectSingle(EntityCondition const & cond,
		AcDb::OpenMode const & kMode,
		char const * sPrompt = NULL,
		bool bHightLight = false);
	//
	//	Select m�t ��i t��ng trong b�n v� AutoCAD
	//	Cho tr��c lo�i ��i t��ng (class name), d�ng nh�c
	//	Tr� v� con tr� t�i object
	//	M� tr� v� 0 l� t�t, kh�c 0 l� l�i

	static int SelectMultiple(AcDbObjectIdArray & idArray,
		EntityCondition const & cond = TrueCondition(),
		char const * selectPrompt=NULL,
		char const * removePrompt=NULL,
		bool bHightLight = false);
	//	H�m ch�n ��i t��ng d�a tr�n c�c �i�u ki�n hi�n c�

	static bool SelectX(AcDbObjectIdArray &idArray,
										EntityCondition const & cond,
										bool bRemoveAll = false);

	static void UnHighLight(const AcDbObjectId & id);

	static void UnHighLight(const AcDbObjectIdArray & ids);

	static void HighLight(const AcDbObjectId & id);
};

//_HDAI_END

#endif //__SELECTIONUTIL_H__
