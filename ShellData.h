// ShellData.h: interface for the ShellData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHELLDATA_H__0892E05A_C759_4F8F_9115_E10FEE1B2609__INCLUDED_)
#define AFX_SHELLDATA_H__0892E05A_C759_4F8F_9115_E10FEE1B2609__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <vector>

#include <acgi.h>
#include <dbfiler.h>
#include <gepnt3d.h>

#define Delimiter ','

class ShellData
{
public:
	ShellData();
	ShellData(ShellData const & shellData);
	~ShellData();

	virtual Acad::ErrorStatus setFaceData(int colorIndex);

	friend std::ostream & operator << (std::ostream & os,
		ShellData const & shellData);

	unsigned int numberOfFaces() const;

	std::vector<AcGePoint3d> mpVertexList;
	std::vector<Adesk::Int32> mpFaceList;

	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer);

	bool WriteText(std::ostream & os) const;
	bool WriteBinary(std::ostream & os) const;

	friend std::ostream & operator << (std::ostream & os, ShellData const & shellData);
};

#endif // !defined(AFX_SHELLDATA_H__0892E05A_C759_4F8F_9115_E10FEE1B2609__INCLUDED_)
