# Microsoft Developer Studio Project File - Name="ImageProcess" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ImageProcess - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ImageProcess.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ImageProcess.mak" CFG="ImageProcess - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ImageProcess - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ImageProcess - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ImageProcess - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "D:\Program Files\OpenCV\otherlibs\_graphics\include" /I "D:\Program Files\OpenCV\otherlibs\highgui" /I "D:\Program Files\OpenCV\cxcore\include" /I "D:\Program Files\OpenCV\cv\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 cv.lib cxcore.lib highgui.lib cvcam.lib vfw32.lib comctl32.lib /nologo /subsystem:windows /machine:I386 /libpath:"D:\Program Files\OpenCV\lib"

!ELSEIF  "$(CFG)" == "ImageProcess - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "D:\Program Files\OpenCV\otherlibs\_graphics\include" /I "D:\Program Files\OpenCV\otherlibs\highgui" /I "D:\Program Files\OpenCV\cxcore\include" /I "D:\Program Files\OpenCV\cv\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 cv.lib cxcore.lib highgui.lib cvcam.lib vfw32.lib comctl32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"D:\Program Files\OpenCV\lib"

!ENDIF 

# Begin Target

# Name "ImageProcess - Win32 Release"
# Name "ImageProcess - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Binaryzation.cpp
# End Source File
# Begin Source File

SOURCE=.\Canny.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorTransform.cpp
# End Source File
# Begin Source File

SOURCE=.\FileUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageFilter.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageProcess.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageProcess.rc
# End Source File
# Begin Source File

SOURCE=.\ImageProcessDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageProcessView.cpp
# End Source File
# Begin Source File

SOURCE=.\LicensePlateRecognitionMain.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MathUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectHSVChannelDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectRGBChannelDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectRotateDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectSize.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectThresholdDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\SlectCalculateStyleDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Binaryzation.h
# End Source File
# Begin Source File

SOURCE=.\Canny.h
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\ColorTransform.h
# End Source File
# Begin Source File

SOURCE=.\FileUtil.h
# End Source File
# Begin Source File

SOURCE=.\ImageFilter.h
# End Source File
# Begin Source File

SOURCE=.\ImageProcess.h
# End Source File
# Begin Source File

SOURCE=.\ImageProcessDoc.h
# End Source File
# Begin Source File

SOURCE=.\ImageProcessView.h
# End Source File
# Begin Source File

SOURCE=.\LicensePlateRecognitionMain.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MathUtil.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SelectHSVChannelDialog.h
# End Source File
# Begin Source File

SOURCE=.\SelectRGBChannelDialog.h
# End Source File
# Begin Source File

SOURCE=.\SelectRotateDialog.h
# End Source File
# Begin Source File

SOURCE=.\SelectSize.h
# End Source File
# Begin Source File

SOURCE=.\SelectThresholdDialog.h
# End Source File
# Begin Source File

SOURCE=.\SlectCalculateStyleDialog.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ImageProcess.ico
# End Source File
# Begin Source File

SOURCE=.\res\ImageProcess.rc2
# End Source File
# Begin Source File

SOURCE=.\res\ImageProcessDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
