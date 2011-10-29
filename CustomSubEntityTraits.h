// CustomSubEntityTraits.h: interface for the CustomSubEntityTraits class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUSTOMSUBENTITYTRAITS_H__D239BEA7_B71C_47CF_AD66_75A65D848455__INCLUDED_)
#define AFX_CUSTOMSUBENTITYTRAITS_H__D239BEA7_B71C_47CF_AD66_75A65D848455__INCLUDED_


#include <acgi.h>

class CustomSubEntityTraits: public AcGiSubEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS(CustomSubEntityTraits);
	CustomSubEntityTraits();
	~CustomSubEntityTraits();
	
	virtual void setColor(const Adesk::UInt16 color);
	virtual void setLayer(const AcDbObjectId layerId);
	virtual void setLineType(const AcDbObjectId linetypeId);
	virtual void setSelectionMarker(const Adesk::Int32 markerId);
	virtual void setFillType(const AcGiFillType fillType);
	
	virtual Adesk::UInt16 color() const;
	virtual AcDbObjectId layerId() const;
	virtual AcDbObjectId lineTypeId() const;
	virtual AcGiFillType fillType() const;
public:
	
#ifdef CAD2000
	virtual void setTrueColor(const AcCmEntityColor& color){};
	virtual void setLineWeight(const AcDb::LineWeight lw) {};
	virtual void setLineTypeScale(double dScale = 1.0) {};
	virtual void setThickness(double dThickness) {};
	virtual void setPlotStyleName(AcDb::PlotStyleNameType type, const AcDbObjectId & id = AcDbObjectId::kNull) {}
	// Return current settings.
	//
	virtual AcCmEntityColor trueColor() const {return AcCmEntityColor();}
	virtual AcDb::LineWeight lineWeight() const {return AcDb::kLnWt000;}
	virtual double lineTypeScale() const {return 0.0;}
	virtual double thickness() const {return 0.0;}
#endif CAD2000
	
private:
	Adesk::UInt16	mColorIndex;
	AcDbObjectId	mLayerId;
	AcDbObjectId	mLinetypeId;
	Adesk::Int32	mMarkerId;
	AcGiFillType	mFillType;
};

#endif // !defined(AFX_CUSTOMSUBENTITYTRAITS_H__D239BEA7_B71C_47CF_AD66_75A65D848455__INCLUDED_)
