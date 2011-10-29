// CustomWorldDraw.cpp: implementation of the CustomWorldDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "CustomWorldDraw.h"
#include "CustomSubEntityTraits.h"
#include "CustomWorldGeometry.h"
#include "CustomContext.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Implementation of CustomWorldDraw class

ACRX_DEFINE_MEMBERS(CustomWorldDraw);

CustomWorldDraw::CustomWorldDraw(): mDeviation(0.1)
{
	mpSubEntityTraits = new CustomSubEntityTraits;
	mpWorldGeometry = new CustomWorldGeometry(this);
	mpContext		  = new CustomContext;
}

CustomWorldDraw::~CustomWorldDraw()
{
	delete mpSubEntityTraits;
	delete mpWorldGeometry;
	// Once the worldDraw object gets ShellData, the custom
	// draw entity will hold its pointer. Hence mpShellData
	// is not deleted here, it is deleted by the CustomDrawEntity's
	// destructor.
	delete mpContext;
}

AcGiRegenType CustomWorldDraw::regenType() const
{
	return	kAcGiHideOrShadeCommand;
}

Adesk::Boolean CustomWorldDraw::regenAbort() const
{
	return	Adesk::kFalse;
}

AcGiSubEntityTraits& CustomWorldDraw::subEntityTraits() const
{
	return *mpSubEntityTraits;
}

AcGiWorldGeometry& CustomWorldDraw::geometry() const
{
	return *mpWorldGeometry;
}

Adesk::Boolean CustomWorldDraw::isDragging() const
{
	return Adesk::kFalse;
}

double CustomWorldDraw::deviation(const AcGiDeviationType,
								 const AcGePoint3d&) const
{
	return mDeviation;
}

Adesk::UInt32 CustomWorldDraw::numberOfIsolines() const
{
	return 1;
}


ShellDataArray & CustomWorldDraw::shellDataArray()
{
	return mpShellDataArray;
}

ShellDataArray const & CustomWorldDraw::shellDataArray() const
{
	return mpShellDataArray;
}

void CustomWorldDraw::setDeviation(double dev)
{
	mDeviation = dev;
}

bool CustomWorldDraw::WriteText(std::ostream & os) const
{
	using namespace std;

	ShellDataArray::const_iterator it;
	int i = 0;
	os << "No. of shells:"<<endl;
	os << mpShellDataArray.size()<<endl;
	int nColor = 0,
		nRed = 0,
		nGreen = 0,
		nBlue = 0;

	int nCount = 0;

	for (it = mpShellDataArray.begin(); it!=mpShellDataArray.end(); it++, i++)
	{
		os <<nRed <<Delimiter<<nGreen<<Delimiter<< nBlue <<endl;

		nCount+=it->numberOfFaces();

		os << *it;
		os << "====================================="<< endl;
	}

	ads_printf("\nTotal of %i faces", nCount);

	return true;
}

bool CustomWorldDraw::WriteBinary(std::ostream & os) const
{
/*	using namespace std;

 ShellDataArray::const_iterator it;
 int i = 0;
 int nIntSize = sizeof(int),
 nPointSize = 3*sizeof(double);

	int nShells = shellDataArray().size();

	 os.write((char *)&nShells, nIntSize);

		int nColor = 0,
		nColors[3] = {0,0,0},
		nRed = 0,
		nGreen = 0,
		nBlue = 0;

		 int nCount = 0;

			for (it = shellDataArray().begin(); it!=shellDataArray().end(); it++, i++)
			{
			os.write((char *)nColors,3*nIntSize);

			 nCount+=it->numberOfFaces();

				os << (*it).WriteBinary(os);
				}

				 ads_printf("\nTotal of %i faces", nCount);
	*/
	return true;
}

std::vector<int> & CustomWorldDraw::Colors()
{
	return mColors;
}

AcGiContext *  CustomWorldDraw::context()
{
	ads_printf("\nCustomWorldDraw::context");
	return mpContext;
}

AcGiGeometry *			CustomWorldDraw::rawGeometry() const
{
	ads_printf("\nCustomWorldDraw::rawGeometry");
	return mpWorldGeometry;
}

