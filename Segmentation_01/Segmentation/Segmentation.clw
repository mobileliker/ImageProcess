; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSegmentationDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Segmentation.h"
LastPage=0

ClassCount=9
Class1=CSegmentationApp
Class2=CSegmentationDoc
Class3=CSegmentationView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_SEGMENTYPE
Class5=CChildFrame
Class6=CAboutDlg
Resource4=IDD_DIALOG_CONTOURPARAMETER
Resource5=IDD_ABOUTBOX (English (U.S.))
Resource6=IDR_SEGMENTYPE (English (U.S.))
Class7=COpeningParameterDialog
Resource7=IDD_DIALOG_WATERSHED (English (U.S.))
Class8=CWatershedParameterDialog
Resource8=IDD_DIALOG_OPENINGPARAMETER (English (U.S.))
Class9=CContourParameterDialog
Resource9=IDR_MAINFRAME (English (U.S.))

[CLS:CSegmentationApp]
Type=0
HeaderFile=Segmentation.h
ImplementationFile=Segmentation.cpp
Filter=N

[CLS:CSegmentationDoc]
Type=0
HeaderFile=SegmentationDoc.h
ImplementationFile=SegmentationDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CSegmentationDoc

[CLS:CSegmentationView]
Type=0
HeaderFile=SegmentationView.h
ImplementationFile=SegmentationView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_MENUITEM_GETSHISTOGRAM


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FILE_OPEN


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=Segmentation.cpp
ImplementationFile=Segmentation.cpp
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

[MNU:IDR_SEGMENTYPE]
Type=1
Class=CSegmentationView
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


[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_SEGMENTYPE (English (U.S.))]
Type=1
Class=CSegmentationView
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
Command22=ID_MENUITEM_CANNY
Command23=ID_MENUITEM_GETSCANNELS
Command24=ID_MENUITEM_GETRCANNELS
Command25=ID_MENUITEM_GETSHISTOGRAM
Command26=ID_MENUITEM_GETSOSTUTHRESHOLD
Command27=ID_MENUITEM_GETSFLAGIMAGE
Command28=ID_MENUITEM_GETSFLAGIMAGEOPENING
Command29=ID_MENUITEM_GETGRADIENT
Command30=ID_MENUITEM_GETMORPHOLOGYGRADIENT
Command31=ID_MENUITEM_GETGRADIENTFLAG
Command32=ID_MENUITEM_GETWATERSHEDOPENCV
Command33=ID_MENUITEM_GETMAXIMUMPOINT
Command34=ID_MENUITEM_GETORIGINALSEGMENTATIONOPENCV
Command35=ID_MENUITEM_GETSSEGMENTATIONOPENCV
Command36=ID_MENUITEM_GETRSEGMENTATIONOPENCV
Command37=ID_MENUITEM_GETCONTOURLINEMANUAL
CommandCount=37

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

[DLG:IDD_DIALOG_OPENINGPARAMETER (English (U.S.))]
Type=1
Class=COpeningParameterDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CIRCLESCOPE,static,1342308352
Control4=IDC_EDIT_CIRCLESCOPE,edit,1350631552
Control5=IDC_TIMES,static,1342308352
Control6=IDC_EDIT_TIMES,edit,1350631552

[CLS:COpeningParameterDialog]
Type=0
HeaderFile=OpeningParameterDialog.h
ImplementationFile=OpeningParameterDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT4
VirtualFilter=dWC

[DLG:IDD_DIALOG_WATERSHED (English (U.S.))]
Type=1
Class=CWatershedParameterDialog
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_X1,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_Y1,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_X2,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_Y2,edit,1350631552

[CLS:CWatershedParameterDialog]
Type=0
HeaderFile=WatershedParameterDialog.h
ImplementationFile=WatershedParameterDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CWatershedParameterDialog

[DLG:IDD_DIALOG_CONTOURPARAMETER]
Type=1
Class=CContourParameterDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_X,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_Y,edit,1350631552

[CLS:CContourParameterDialog]
Type=0
HeaderFile=ContourParameterDialog.h
ImplementationFile=ContourParameterDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CContourParameterDialog

