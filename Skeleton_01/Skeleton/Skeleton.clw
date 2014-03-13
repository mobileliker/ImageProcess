; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSkeletonDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Skeleton.h"
LastPage=0

ClassCount=8
Class1=CSkeletonApp
Class2=CSkeletonDoc
Class3=CSkeletonView
Class4=CMainFrame

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_SKELETTYPE
Class5=CChildFrame
Class6=CAboutDlg
Resource4=IDD_DIALOG_SELECTSIZE
Resource5=IDR_SKELETTYPE (English (U.S.))
Resource6=IDD_DIALOG_SELECTTHRESHOLD
Class7=CSelectSizeDialog
Resource7=IDD_ABOUTBOX (English (U.S.))
Class8=CSelectThresholdDialog
Resource8=IDR_MAINFRAME (English (U.S.))

[CLS:CSkeletonApp]
Type=0
HeaderFile=Skeleton.h
ImplementationFile=Skeleton.cpp
Filter=N

[CLS:CSkeletonDoc]
Type=0
HeaderFile=SkeletonDoc.h
ImplementationFile=SkeletonDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CSkeletonDoc

[CLS:CSkeletonView]
Type=0
HeaderFile=SkeletonView.h
ImplementationFile=SkeletonView.cpp
Filter=C
LastObject=ID_MENUITEM_GETSMOOTHIMAGE
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CMDIFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M
BaseClass=CMDIChildWnd
VirtualFilter=mfWC


[CLS:CAboutDlg]
Type=0
HeaderFile=Skeleton.cpp
ImplementationFile=Skeleton.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
CommandCount=8
Command8=ID_APP_ABOUT

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
CommandCount=8
Command8=ID_APP_ABOUT

[MNU:IDR_SKELETTYPE]
Type=1
Class=CSkeletonView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
CommandCount=21
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE


[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_SKELETTYPE (English (U.S.))]
Type=1
Class=CSkeletonView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT
Command22=ID_MENUITEM_GETBCANNELS
Command23=ID_MENUITEM_GETSMOOTHIMAGE
Command24=ID_MENUITEM_GETTHRESHOLDIMAGEOSTU
Command25=ID_MENUITEM_GETTHRESHOLDIMAGEMANNAL
Command26=ID_MENUITEM_GETTHINIMAGE
Command27=ID_MENUITEM_GETTHINIMAGEZHANG
Command28=ID_MENUITEM_GETTHINIMAGEROSEENFELD
Command29=ID_MENUITEM_GETGRAYIMAGE
Command30=ID_MENUITEM_ROOTGETTHRESHOLDIMAGEOSTU
Command31=ID_MENUITEM_ROOTGETTHRESHOLDIMAGEMANNAL
Command32=ID_MENUITEM_GETTHINIMAGEDISTANCE
Command33=ID_MENUITEM_SOYBEANGETGRAYIMAGE
Command34=ID_MENUITEM32795
Command35=ID_MENUITEM_GETISOLATEPOINT
Command36=ID_MENUITEM_COMPLETEISOLATE
Command37=ID_MENUITEM_GETENDPOINT
Command38=ID_MENUITEM_COMPLETEEND
Command39=ID_MENUITEM_ALL
Command40=ID_MENUITEM_COMPLETEMANNAL
Command41=ID_MENUITEM_GETBRACH
Command42=ID_MENUITEM_CALBRACHDATA
Command43=ID_MENUITEM_SAVEIMAGE
CommandCount=43

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG_SELECTSIZE]
Type=1
Class=CSelectSizeDialog
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FILTERSIZE,edit,1350631552

[CLS:CSelectSizeDialog]
Type=0
HeaderFile=SelectSizeDialog.h
ImplementationFile=SelectSizeDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CSelectSizeDialog
VirtualFilter=dWC

[DLG:IDD_DIALOG_SELECTTHRESHOLD]
Type=1
Class=CSelectThresholdDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_THRESHOLD,edit,1350631552
Control5=IDC_RADIO_AES,button,1342373897
Control6=IDC_RADIO_DES,button,1342242825

[CLS:CSelectThresholdDialog]
Type=0
HeaderFile=SelectThresholdDialog.h
ImplementationFile=SelectThresholdDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RADIO_AES

