// ShellDataArray.cpp: implementation of the ShellDataArray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShellDataArray.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ShellDataArray::ShellDataArray()
{
}
ShellDataArray::~ShellDataArray()
{
}

bool ShellDataArray::WriteText(std::ostream & os) const
{
	using namespace std;

	int nCount = 0;
	ShellDataArray::const_iterator it;
	for (it = begin(); it!=end(); it++)
	{
		nCount+=it->mpFaceList.size();
		os << *it;
		os << endl << "====================================="<< endl;
	}

	ads_printf("\nTotal of %i faces", nCount);

	return true;
}

std::ostream & operator << (std::ostream & os,
							ShellDataArray const & shellDataArray)
{
	using namespace std;

	int nCount = 0;
	ShellDataArray::const_iterator it;
	for (it = shellDataArray.begin(); it!=shellDataArray.end(); it++)
	{
		nCount+=it->mpFaceList.size();
		os << *it;
		os << endl << "====================================="<< endl;
	}

	ads_printf("\nTotal of %i faces", nCount);

	return os;
}

Acad::ErrorStatus ShellDataArray::dwgOutFields(AcDbDwgFiler* filer) const
{
	int i,
		nSize = size();

	filer->writeInt32(nSize);

	for (i = 0; i < nSize; i++)
		at(i).dwgOutFields(filer);

	return Acad::eOk;
}

Acad::ErrorStatus ShellDataArray::dwgInFields(AcDbDwgFiler* filer)
{
	int nSize;
	filer->readInt32((Adesk::Int32*)&nSize);
	resize(nSize);

	int i;

	for (i = 0; i < nSize; i++)
		at(i).dwgInFields(filer);

	return Acad::eOk;
}
