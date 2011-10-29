#include "stdafx.h"

#include "CustomContext.h"
#include <dbapserv.h>


//  Implementation of CustomContext

ACRX_DEFINE_MEMBERS(CustomContext);

CustomContext::CustomContext()
{
}

CustomContext::~CustomContext()
{
}

Adesk::Boolean     CustomContext::isPsOut() const
{
	return Adesk::kFalse;
}
Adesk::Boolean     CustomContext::isPlotGeneration() const
{
	return Adesk::kFalse;
}

AcDbDatabase *     CustomContext::database() const
{
	return acdbHostApplicationServices()->workingDatabase();
}

bool     CustomContext::isBoundaryClipping() const
{
	return false;
}

