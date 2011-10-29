// BsSelectionUtil.h: interface for the BsSelectionUtil class.
//
//	Líp c¸c tiÖn Ých chän ®èi t­îng
//
//////////////////////////////////////////////////////////////////////

#ifndef __ENTITYFUNCTIONOBJECT_H__
#define __ENTITYFUNCTIONOBJECT_H__

//#include <Hdai/HdaiDef.h>

#include <dbmain.h>

//_HDAI_BEGIN

struct EntityCondition
{
	virtual bool operator ()(AcDbEntity * pEnt) const
	{
		return false;
	}
};

struct TrueCondition : public EntityCondition
{
	virtual bool operator ()(AcDbEntity * pEnt) const
	{
		return true;
	}
};

struct BinaryCondition : public EntityCondition
{
	BinaryCondition(EntityCondition const & first, EntityCondition const & second): m_first(first), m_second(second)
	{
	}
	
	EntityCondition const & m_first;
	EntityCondition const & m_second;
};

struct UnaryCondition : public EntityCondition
{
	UnaryCondition(EntityCondition const & first): m_first(first)
	{
	}
	
	EntityCondition const & m_first;
};

struct AndCondition : public BinaryCondition
{
	AndCondition(EntityCondition const & first, EntityCondition const & second) : BinaryCondition(first,second)
	{
	}
	
	virtual bool operator ()(AcDbEntity * pEnt) const
	{
		return m_first(pEnt) && m_second(pEnt);
	}
};

struct OrCondition : public BinaryCondition
{
	OrCondition(EntityCondition const & first, EntityCondition const & second) : BinaryCondition(first,second)
	{
	}
	
	virtual bool operator ()(AcDbEntity * pEnt) const
	{
		return m_first(pEnt) || m_second(pEnt);
	}
};

struct NotCondition : public UnaryCondition
{
	NotCondition(EntityCondition const & first) : UnaryCondition(first)
	{
	}
	
	virtual bool operator ()(AcDbEntity * pEnt) const
	{
		return !m_first(pEnt);
	}
};

struct KindOf : public EntityCondition
{
	KindOf(AcRxClass * rxClass) : m_rxClass(rxClass)
	{
	}
	
	virtual bool operator ()(AcDbEntity * pEnt) const
	{
		return pEnt->isKindOf(m_rxClass)!=0;
	}
	
	AcRxClass * m_rxClass;
};

struct Layer : public EntityCondition
{
	Layer(char const *sLayerName) : m_sLayerName(sLayerName)
	{
	}
	
/*	virtual bool operator ()(AcDbEntity * pEnt) const
	{
		return !strncmp(m_sLayerName, pEnt->layer(), strlen(m_sLayerName));
	}
*/	
	char const * const m_sLayerName;
};

struct Color : public EntityCondition
{
	Color(int nColor) : m_nColor(nColor)
	{
	}
	
	virtual bool operator ()(AcDbEntity * pEnt) const
	{
		return m_nColor == pEnt->colorIndex();
	}
	
	int m_nColor;
};

inline AndCondition operator && (EntityCondition const & first, 
					  EntityCondition const & second)
{
	return AndCondition(first,second);
}

inline OrCondition operator || (EntityCondition const & first, 
					 EntityCondition const & second)
{
	return OrCondition(first,second);
}

inline NotCondition operator ! (EntityCondition const & first)
{
	return NotCondition(first);
}

//_HDAI_END

#endif //__ENTITYFUNCTIONOBJECT_H__
