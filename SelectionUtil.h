// SelectionUtil.h: interface for the SelectionUtil class.
//
//	Líp c¸c tiÖn Ých chän ®èi t­îng
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
	//	C¸c kiÓu select ®èi t­îng
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
	//	Select mét ®èi t­îng trong b¶n vÏ AutoCAD
	//	Cho tr­íc lo¹i ®èi t­îng (class name), dßng nh¾c
	//	Tr¶ vÒ object id cña ®èi t­îng
	//	M· tr¶ vÒ true lµ tèt, kh¸c false lµ lçi

	static AcDbEntity * SelectSingle(EntityCondition const & cond,
		AcDb::OpenMode const & kMode,
		char const * sPrompt = NULL,
		bool bHightLight = false);
	//
	//	Select mét ®èi t­îng trong b¶n vÏ AutoCAD
	//	Cho tr­íc lo¹i ®èi t­îng (class name), dßng nh¾c
	//	Tr¶ vÒ con trá tíi object
	//	M· tr¶ vÒ 0 lµ tèt, kh¸c 0 lµ lçi

	static int SelectMultiple(AcDbObjectIdArray & idArray,
		EntityCondition const & cond = TrueCondition(),
		char const * selectPrompt=NULL,
		char const * removePrompt=NULL,
		bool bHightLight = false);
	//	Hµm chän ®èi t­îng dùa trªn c¸c ®iÒu kiÖn hiÖn cã

	static bool SelectX(AcDbObjectIdArray &idArray,
										EntityCondition const & cond,
										bool bRemoveAll = false);

	static void UnHighLight(const AcDbObjectId & id);

	static void UnHighLight(const AcDbObjectIdArray & ids);

	static void HighLight(const AcDbObjectId & id);
};

//_HDAI_END

#endif //__SELECTIONUTIL_H__
