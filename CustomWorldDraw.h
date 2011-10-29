// CustomWorldDraw.h: interface for the CustomWorldDraw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUSTOMWORLDDRAW_H__D8C861DC_DCA7_423E_8966_4BD4EC7F1CC3__INCLUDED_)
#define AFX_CUSTOMWORLDDRAW_H__D8C861DC_DCA7_423E_8966_4BD4EC7F1CC3__INCLUDED_

#include <acgi.h>
#include "ShellDataArray.h"

// Custom worldDraw object is sent in a call to the
// entitiy's worldDraw function. The entity will then
// end up calling the worldGeometry class's shell function.
// In this case, the CustomWorldDraw's shell member
// function will be called.


class CustomWorldDraw: public AcGiWorldDraw
{
public:
/*
#ifdef CAD2000
	virtual AcGiGeometry * rawGeometry() const {return 0;}
	virtual AcGiContext * context() {return 0;}
#endif CAD2000

public:
 ACRX_DECLARE_MEMBERS(CustomWorldDraw);
	CustomWorldDraw();
	~CustomWorldDraw();

 virtual AcGiRegenType regenType() const;
 virtual Adesk::Boolean regenAbort() const;
 virtual AcGiSubEntityTraits& subEntityTraits() const;
 virtual AcGiWorldGeometry& geometry() const;
 virtual Adesk::Boolean isDragging() const;
 virtual double deviation(const AcGiDeviationType,
					 const AcGePoint3d&) const;
 virtual Adesk::UInt32 numberOfIsolines() const;
*/
    ACRX_DECLARE_MEMBERS(CustomWorldDraw);
	CustomWorldDraw();
	virtual ~CustomWorldDraw();

    virtual AcGiRegenType           regenType() const;
    virtual Adesk::Boolean          regenAbort() const;
    virtual AcGiSubEntityTraits&    subEntityTraits() const;
	virtual AcGiGeometry *			rawGeometry() const;
    virtual AcGiWorldGeometry&      geometry() const;
    virtual Adesk::Boolean          isDragging() const;
    virtual double                  deviation(const AcGiDeviationType, 
					      const AcGePoint3d&) const;
    virtual Adesk::UInt32           numberOfIsolines() const;	
	virtual AcGiContext *			context();

public:
	ShellDataArray & shellDataArray();
	ShellDataArray const & shellDataArray() const;
	void					setDeviation(double);

	friend std::ostream & operator << (std::ostream & os,
		CustomWorldDraw const & worldDraw);

	std::vector<int> & Colors();

public:
	AcGiSubEntityTraits*	mpSubEntityTraits;

private:
	std::vector<std::string> mEntities;

	ShellDataArray mpShellDataArray;
	std::vector<int> mColors;

	AcGiWorldGeometry*		mpWorldGeometry;
	double					mDeviation;
	AcGiContext*			mpContext;

public:
	bool WriteText(std::ostream & os) const;
	bool WriteBinary(std::ostream & os) const;
};

#endif // !defined(AFX_CUSTOMWORLDDRAW_H__D8C861DC_DCA7_423E_8966_4BD4EC7F1CC3__INCLUDED_)
