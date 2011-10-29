#ifndef CUSTACGI_H
#define CUSTACGI_H 1

#include "acgi.h"

// AcGiContext abstracts out the commonality between 
// AcGiViewportDraw and AcGiWorldDraw. This allows you 
// to code graphics routines in terms of AcGiContext that 
// will work in either case. To maintain their original signatures,
// AcGiWorldDraw and AcGiViewportDraw now derive from AcGiContext.
// Only the database member function is implemented.  
class CustomContext : public AcGiContext
{
public:
	ACRX_DECLARE_MEMBERS(CustomContext);
	CustomContext();
	virtual ~CustomContext();

	Adesk::Boolean          isPsOut() const;
    Adesk::Boolean          isPlotGeneration() const;
    AcDbDatabase *          database() const;
    bool          isBoundaryClipping() const;

};

#endif
