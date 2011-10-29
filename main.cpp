
#include "stdafx.h"
#include "Commands.h"

#ifdef CAD2000
#include <migrtion.h>
#include <dbapserv.h>
#endif CAD2000

#include <aced.h>
#include <adslib.h>

#include "CustomDrawEntity.h"

/////////////////////////////////Het ACAD14

void initApp()
{
	CustomDrawEntity::rxInit();
	Commands::Register();

	acrxBuildClassHierarchy();
}

void unloadApp()
{
	deleteAcRxClass(CustomDrawEntity::desc());
	Commands::UnRegister();
}


#ifdef CAD2000

extern "C" AcRx::AppRetCode acrxEntryPoint( AcRx::AppMsgCode msg, void* pkt)
{
	switch( msg ) 
	{
	case AcRx::kInitAppMsg:
		//An ARX application is locked to memory by default.
		//You must make the following function call to unlock it.
		acrxDynamicLinker->unlockApplication(pkt);
		//support MDI
		acrxDynamicLinker->registerAppMDIAware(pkt);
		// Create the an instance of the class DocGlobals which
		// cares on setting the right global variables when a document
		// is activated.
		// After this call the per-document global variables can be
		// accessed through the global pointer gpActualData
		initApp();
		break;
	case AcRx::kUnloadAppMsg:

		unloadApp();
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}
#else	//	CAD2000


extern "C" AcRx::AppRetCode acrxEntryPoint( AcRx::AppMsgCode msg, void* pkt)
{
	switch( msg ) {
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		initApp();
		break;
	case AcRx::kUnloadAppMsg:
		deleteAcRxClass(CustomDrawEntity::desc());
		unloadApp();
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}
#endif //	CAD2000


