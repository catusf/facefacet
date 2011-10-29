/*-----------------------------------------------
File name    : Commands.h
Author       : 

  Description  : 
-----------------------------------------------*/
#ifndef _COMMANDS_H
#define _COMMANDS_H


struct Command
{
	typedef void (*CommandFunction) (void);

	char * m_sGlobalCmd;
	char * m_sLocalCmd;
	char * m_sDesc;
	CommandFunction m_pFunctionCmd;

	static char * m_sCommandGroup;
};

class Commands
{
public:
	static void Register();
	
	static void UnRegister();
	
public:
	static void NewExtrude();
	
	static void shadeFace();
	
	static void calcMassProp();
	
	static void setFacetDeviation();
	
	static void setColorIndex();
private:
	// colorIndex set by user. Entity will shade itself in this color.
	static	int colorIndex; 
	
	// Facet deviation. Smaller value
	// causes more facets to be drawn and
	// a more accurate represention of the
	// geometry is obtained. This is set
	// by the user.
	static double deviation; 
};

#endif // _COMMANDS_H
