// ShellDataArray.h: interface for the ShellDataArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHELLDATAARRAY_H__D2259BBF_84E8_4B50_B9D2_691D739939C6__INCLUDED_)
#define AFX_SHELLDATAARRAY_H__D2259BBF_84E8_4B50_B9D2_691D739939C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <iostream>
#include "ShellData.h"

class ShellDataArray: public std::vector<ShellData>
{
public:
	ShellDataArray();

	~ShellDataArray();

	bool WriteText(std::ostream & os) const;
	bool WriteBinary(std::ostream & os) const;

	friend std::ostream & operator << (std::ostream & os,
							ShellDataArray const & shellDataArray);

	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const;

	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer);
};

#endif // !defined(AFX_SHELLDATAARRAY_H__D2259BBF_84E8_4B50_B9D2_691D739939C6__INCLUDED_)
