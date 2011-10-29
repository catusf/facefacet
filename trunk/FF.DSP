# Microsoft Developer Studio Project File - Name="FF" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=FF - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FF.MAK".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FF.MAK" CFG="FF - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FF - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "FF - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "FF - Win32 Release2000" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "FF - Win32 Debug2000" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "FF - Win32 Win32 Release2000 FJ" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FF - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\WinRel"
# PROP BASE Intermediate_Dir ".\WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Executable"
# PROP Intermediate_Dir "C:\VcTemp\FF\Release"
# PROP Ignore_Export_Lib 1
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "C:\Program Files\ObjectARXR14\INC" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "ACRXAPP" /D "RADPACK" /D "__STL_USE_MFC" /D "__SGI_STL_OWN_IOSTREAMS" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 acad.lib acedapi.lib acgiapi.lib rxapi.lib libacge.lib /nologo /base:"0x1c000000" /entry:"DllEntryPoint@12" /subsystem:windows /dll /machine:I386 /nodefaultlib:"MSVCRT.lib" /out:".\Executable\ff1400.arx" /libpath:"C:\Program Files\ObjectARXR14\LIB"

!ELSEIF  "$(CFG)" == "FF - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\WinDebug"
# PROP BASE Intermediate_Dir ".\WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Executable"
# PROP Intermediate_Dir "C:\VcTemp\FF\Debug"
# PROP Ignore_Export_Lib 0
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /MD /W3 /Gm /GX /ZI /Od /I "..\..\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "ACRXAPP" /D "RADPACK" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 acad.lib acedapi.lib acgiapi.lib rxapi.lib libacge.lib /nologo /base:"0x1c000000" /entry:"DllEntryPoint@12" /subsystem:windows /dll /debug /machine:I386 /out:".\Executable\ff1400.arx"

!ELSEIF  "$(CFG)" == "FF - Win32 Release2000"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FF___Win32_Release2000"
# PROP BASE Intermediate_Dir "FF___Win32_Release2000"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "C:\VcTemp\FF\Release2000"
# PROP Intermediate_Dir "C:\VcTemp\FF\Release2000"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\..\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "ACRXAPP" /D "RADPACK" /D "__STL_USE_MFC" /D "__SGI_STL_OWN_IOSTREAMS" /YX /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /O2 /I "C:\PROGRAM FILES\OBJECTARX 2000\INC" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "ACRXAPP" /D "RADPACK" /D "__STL_USE_MFC" /D "__SGI_STL_OWN_IOSTREAMS" /D "CAD2000" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 acad.lib acedapi.lib acgiapi.lib rxapi.lib libacge.lib /nologo /base:"0x1c000000" /entry:"DllEntryPoint@12" /subsystem:windows /dll /machine:I386 /out:".\Release\ff.arx"
# ADD LINK32 rxapi.lib acdb15.lib acad.lib acrx15.lib acedapi.lib acgiapi.lib acge15.lib acutil15.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /nodefaultlib:"MSVCRT.lib" /out:".\Redist\ff2k.arx" /libpath:"C:\PROGRAM FILES\OBJECTARX 2000\lib"

!ELSEIF  "$(CFG)" == "FF - Win32 Debug2000"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FF___Win32_Debug2000"
# PROP BASE Intermediate_Dir "FF___Win32_Debug2000"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "C:\VcTemp\FF\Debug2000"
# PROP Intermediate_Dir "C:\VcTemp\FF\Debug2000"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "C:\PROGRAM FILES\OBJECTARX 2000\INC" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "ACRXAPP" /D "RADPACK" /D "__STL_USE_MFC" /D "__SGI_STL_OWN_IOSTREAMS" /D "CAD2000" /D "_WINDLL" /D "_AFXDLL" /YX /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /Od /I "C:\PROGRAM FILES\OBJECTARX 2000\INC" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "ACRXAPP" /D "RADPACK" /D "__STL_USE_MFC" /D "__SGI_STL_OWN_IOSTREAMS" /D "CAD2000" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rxapi.lib acdb15.lib acad.lib acrx15.lib acedapi.lib acgiapi.lib acge15.lib acutil15.lib /nologo /subsystem:windows /dll /machine:I386 /out:".\Executable\ff2000.arx" /libpath:"C:\PROGRAM FILES\OBJECTARX 2000\lib"
# ADD LINK32 rxapi.lib acdb15.lib acad.lib acrx15.lib acedapi.lib acgiapi.lib acge15.lib acutil15.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"MSVCRT.lib" /out:".\Redist\ff2kd.arx" /libpath:"C:\PROGRAM FILES\OBJECTARX 2000\lib"

!ELSEIF  "$(CFG)" == "FF - Win32 Win32 Release2000 FJ"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FF___Win32_Win32_Release2000_FJ"
# PROP BASE Intermediate_Dir "FF___Win32_Win32_Release2000_FJ"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "C:\VcTemp\FF\Release2000_FJ"
# PROP Intermediate_Dir "C:\VcTemp\FF\Release2000_FJ"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "C:\PROGRAM FILES\OBJECTARX 2000\INC" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "ACRXAPP" /D "RADPACK" /D "__STL_USE_MFC" /D "__SGI_STL_OWN_IOSTREAMS" /D "CAD2000" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /O1 /I "C:\PROGRAM FILES\OBJECTARX 2000\INC" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "ACRXAPP" /D "RADPACK" /D "__STL_USE_MFC" /D "__SGI_STL_OWN_IOSTREAMS" /D "CAD2000" /D "_WINDLL" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rxapi.lib acdb15.lib acad.lib acrx15.lib acedapi.lib acgiapi.lib acge15.lib acutil15.lib /nologo /subsystem:windows /dll /machine:I386 /nodefaultlib:"MSVCRT.lib" /out:".\Redist\ff2k.arx" /libpath:"C:\PROGRAM FILES\OBJECTARX 2000\lib"
# ADD LINK32 rxapi.lib acdb15.lib acad.lib acrx15.lib acedapi.lib acgiapi.lib acge15.lib acutil15.lib /nologo /subsystem:windows /dll /machine:I386 /nodefaultlib:"MSVCRT.lib" /out:".\Redist\fj2k.arx" /libpath:"C:\PROGRAM FILES\OBJECTARX 2000\lib"

!ENDIF 

# Begin Target

# Name "FF - Win32 Release"
# Name "FF - Win32 Debug"
# Name "FF - Win32 Release2000"
# Name "FF - Win32 Debug2000"
# Name "FF - Win32 Win32 Release2000 FJ"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\Commands.cpp
# End Source File
# Begin Source File

SOURCE=.\CustomContext.cpp
# End Source File
# Begin Source File

SOURCE=.\CustomDrawEntity.cpp
# End Source File
# Begin Source File

SOURCE=.\CustomSubEntityTraits.cpp
# End Source File
# Begin Source File

SOURCE=.\CustomWorldDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\CustomWorldGeometry.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectionUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\ShellData.cpp
# End Source File
# Begin Source File

SOURCE=.\ShellDataArray.cpp
# End Source File
# Begin Source File

SOURCE=.\stdafx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Util.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\Commands.h
# End Source File
# Begin Source File

SOURCE=.\CustomContext.h
# End Source File
# Begin Source File

SOURCE=.\CustomDrawEntity.h
# End Source File
# Begin Source File

SOURCE=.\CustomSubEntityTraits.h
# End Source File
# Begin Source File

SOURCE=.\CustomWorldDraw.h
# End Source File
# Begin Source File

SOURCE=.\CustomWorldGeometry.h
# End Source File
# Begin Source File

SOURCE=.\FF.def
# End Source File
# Begin Source File

SOURCE=.\SelectionUtil.h
# End Source File
# Begin Source File

SOURCE=.\ShellData.h
# End Source File
# Begin Source File

SOURCE=.\ShellDataArray.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
# Section FF : {7840488C-E588-4EF2-A8B0-71F8D007E88A}
# 	2:20:CLASS: AsdkShellData:AsdkShellData
# 	2:12:custacgi.cpp:custacgi.cpp
# 	2:24:CLASS: AsdkCustomContext:AsdkCustomContext
# 	2:26:CLASS: AsdkCustomWorldDraw:AsdkCustomWorldDraw
# 	2:10:custacgi.h:custacgi.h
# 	2:19:Application Include:FF.H
# 	2:32:CLASS: AsdkCustomSubEntityTraits:AsdkCustomSubEntityTraits
# 	2:30:CLASS: AsdkCustomWorldGeometry:AsdkCustomWorldGeometry
# End Section
