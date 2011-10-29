// CustomSubEntityTraits.cpp: implementation of the CustomSubEntityTraits class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "CustomSubEntityTraits.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Implementation of CustomSubEntityTraits object

ACRX_DEFINE_MEMBERS(CustomSubEntityTraits);

CustomSubEntityTraits::CustomSubEntityTraits()
{
	mColorIndex = 5;
	mMarkerId	= 1;
	mFillType	= kAcGiFillAlways;
}

CustomSubEntityTraits::~CustomSubEntityTraits()
{
}

void CustomSubEntityTraits::setColor(const Adesk::UInt16 color)
{
	mColorIndex = color;
}

void CustomSubEntityTraits::setLayer(const AcDbObjectId layerId)
{
	mLayerId = layerId;
}

void CustomSubEntityTraits::setLineType(const AcDbObjectId linetypeId)
{
	mLinetypeId = linetypeId;
}

void CustomSubEntityTraits::setSelectionMarker(const Adesk::Int32 markerId)
{
	mMarkerId = markerId;
}

void CustomSubEntityTraits::setFillType(const AcGiFillType fillType)
{
	mFillType = fillType;
}

Adesk::UInt16 CustomSubEntityTraits::color() const
{
	return	 mColorIndex;
}

AcDbObjectId CustomSubEntityTraits::layerId() const
{
	return mLayerId;
}

AcDbObjectId CustomSubEntityTraits::lineTypeId() const
{
	return mLinetypeId;
}

AcGiFillType CustomSubEntityTraits::fillType() const
{
	return 	mFillType;
}
