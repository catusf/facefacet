// ShellData.cpp: implementation of the ShellData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "ShellData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ShellData::ShellData()
{
}

ShellData::ShellData(ShellData const & shellData)
{
	mpVertexList = shellData.mpVertexList;
	mpFaceList = shellData.mpFaceList;
}

ShellData::~ShellData()
{
}

unsigned int ShellData::numberOfFaces() const
{
	// Get number of faces:
	unsigned int numFaces = 0;

	Adesk::Int32 const * pTempFaceList = mpFaceList.begin();

	for (unsigned int i = 0; i < mpFaceList.size(); )
	{
		++numFaces;
		unsigned int facePoints = *pTempFaceList;
		pTempFaceList += (facePoints + 1);
		i += (facePoints + 1);
	}

	return numFaces;
}

Acad::ErrorStatus ShellData::setFaceData(int colorIndex)
{
	return Acad::eOk;
}
bool ShellData::WriteBinary(std::ostream & os) const
{
	using namespace std;

	int nIntSize = sizeof(int),
		nPointSize = 3*sizeof(double);

	int nVertices = mpVertexList.size(),
		nFaces = numberOfFaces(),
		nFaceListSize = mpFaceList.size();

	os.write((char *)&nVertices, nIntSize);
	os.write((char *)mpVertexList.begin(), nVertices*nPointSize);

	os.write((char *)&nFaces, nIntSize);
	os.write((char *)&nFaceListSize, nIntSize);
	os.write((char *)mpFaceList.begin(), nIntSize*nFaceListSize);

	return true;
}

bool ShellData::WriteText(std::ostream & os) const
{
	using namespace std;

	int i;

	os << "No. vertices: "<<endl<<mpVertexList.size()<<endl;
	for (i = 0; i< mpVertexList.size(); i++)
	{
		os << mpVertexList[i][0]<< Delimiter<<
			mpVertexList[i][1]<< Delimiter<<
			mpVertexList[i][2]<< endl;
	}

	os << "No. faces: "<<endl;
	//	os << mpFaceList.size()<<endl;
	os << numberOfFaces() << endl;

	int j, nVerts,
		nCurrent = 0;

	do
	{
		nVerts = mpFaceList[nCurrent];
		// os << nVerts << Delimiter;

		for (j = 0; j < nVerts; j++)
		{
			os << mpFaceList[nCurrent+j+1];

			if (j < nVerts-1)
				os << Delimiter;
			else
				os << endl;
		}

		nCurrent+=nVerts+1;
	}
	while (nCurrent < mpFaceList.size());

	return true;
}

std::ostream & operator << (std::ostream & os, ShellData const & shellData)
{
	using namespace std;

	int i;

	os << "No. vertices: "<<endl<<shellData.mpVertexList.size()<<endl;
	for (i = 0; i< shellData.mpVertexList.size(); i++)
	{
		os << shellData.mpVertexList[i][0]<< Delimiter<<
			shellData.mpVertexList[i][1]<< Delimiter<<
			shellData.mpVertexList[i][2]<< endl;
	}

	os << "No. faces: "<<endl;
	//	os << shellData.mpFaceList.size()<<endl;
	os << shellData.numberOfFaces() << endl;

	int j, nVerts,
		nCurrent = 0;

	do
	{
		nVerts = shellData.mpFaceList[nCurrent];
		// os << nVerts << Delimiter;

		for (j = 0; j < nVerts; j++)
		{
			os << shellData.mpFaceList[nCurrent+j+1];

			if (j < nVerts-1)
				os << Delimiter;
			else
				os << endl;
		}

		nCurrent+=nVerts+1;
	}
	while (nCurrent < shellData.mpFaceList.size());

	return os;
}

Acad::ErrorStatus ShellData::dwgInFields(AcDbDwgFiler* filer)
{
	Adesk::UInt32 nSize;

	filer->readItem(&nSize);
	mpVertexList.resize(nSize);

	for (unsigned int i = 0; i < nSize; i++)
		filer->readItem( &(mpVertexList[i]) );

	filer->readItem(&nSize);

	mpFaceList.resize(nSize);
	for (i = 0; i < nSize; i++)
		filer->readItem( &(mpFaceList[i]) );

	return Acad::eOk;
}

Acad::ErrorStatus ShellData::dwgOutFields(AcDbDwgFiler* filer) const
{
	filer->writeInt32(mpVertexList.size());

	for(unsigned int i = 0; i < mpVertexList.size(); i++)
		filer->writeItem(mpVertexList[i]);

	filer->writeInt32(mpFaceList.size());
	for(i =0; i < mpFaceList.size(); i++)
		filer->writeItem(mpFaceList[i]);

	return Acad::eOk;
}
