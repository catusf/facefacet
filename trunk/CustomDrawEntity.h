// CustomDrawEntity.h: interface for the CustomDrawEntity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUSTOMDRAWENTITY_H__B6BC8CB9_515F_4024_B8D9_4DB3A428CA4A__INCLUDED_)
#define AFX_CUSTOMDRAWENTITY_H__B6BC8CB9_515F_4024_B8D9_4DB3A428CA4A__INCLUDED_

#include <adesk.h>
#include <dbents.h>

#include "ShellDataArray.h"

class CustomDrawEntity: public AcDbEntity
{
public:
	ACRX_DECLARE_MEMBERS(CustomDrawEntity);
	
	CustomDrawEntity();
	
	~CustomDrawEntity();
	
	virtual Adesk::Boolean worldDraw(AcGiWorldDraw *);
	
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer);
	
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const;
	
	virtual Acad::ErrorStatus transformBy(const AcGeMatrix3d& xform);

	ShellDataArray & shellDataArray();

	ShellDataArray const & shellDataArray() const;

protected:
	ShellDataArray mpShellDataArray;
};

#endif // !defined(AFX_CUSTOMDRAWENTITY_H__B6BC8CB9_515F_4024_B8D9_4DB3A428CA4A__INCLUDED_)
