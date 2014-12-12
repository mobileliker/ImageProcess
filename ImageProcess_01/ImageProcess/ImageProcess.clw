; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CImageProcessDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ImageProcess.h"
LastPage=0

ClassCount=12
Class1=CImageProcessApp
Class2=CImageProcessDoc
Class3=CImageProcessView
Class4=CMainFrame

ResourceCount=12
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_IMAGEPTYPE
Class5=CChildFrame
Class6=CAboutDlg
Resource4=IDD_DIALOG_SELECTRGBCHANNEL (English (U.S.))
Resource5=IDD_ABOUTBOX (English (U.S.))
Resource6=IDD_DIALOG_SELECTHSVCHANNEL (English (U.S.))
Class7=CSelectThresholdDialog
Resource7=IDR_IMAGEPTYPE (English (U.S.))
Class8=CSelectRGBChannelDialog
Resource8=IDD_DIALOG_SELECTCALSTYLE (English (U.S.))
Class9=CSelectHSVChannelDialog
Resource9=IDD_DIALOG_SELECTSIZE (English (U.S.))
Class10=CSelectSize
Resource10=IDR_MAINFRAME (English (U.S.))
Class11=CSlectCalculateStyleDialog
Resource11=IDD_DIALOG_SELECTTHRESHOLD (English (U.S.))
Class12=CSelectRotateDialog
Resource12=IDD_DIALOG_SELECTROTATE (English (U.S.))

[CLS:CImageProcessApp]
Type=0
HeaderFile=ImageProcess.h
ImplementationFile=ImageProcess.cpp
Filter=N

[CLS:CImageProcessDoc]
Type=0
HeaderFile=ImageProcessDoc.h
ImplementationFile=ImageProcessDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_MENUITEM_GETHisTOGRAM

[CLS:CImageProcessView]
Type=0
HeaderFile=ImageProcessView.h
ImplementationFile=ImageProcessView.cpp
Filter=C
LastObject=ID_MENUITEM_LPR_AUTOTEST
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUITEM_GETGRAYIMAGE


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=ImageProcess.cpp
ImplementationFile=ImageProcess.cpp
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

[MNU:IDR_IMAGEPTYPE]
Type=1
Class=CImageProcessView
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

[MNU:IDR_IMAGEPTYPE (English (U.S.))]
Type=1
Class=CImageProcessView
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
Command21=ID_MENUITEM_GETALLIMAGEPOINT
Command22=ID_MENUITEM_GETGRAYIMAGE
Command23=ID_MENUITEM_ROTATE
Command24=ID_MENUITEM_GETREVERSEIMAGE
Command25=ID_MENUITEM_GETRGBCHANNELIMAGE
Command26=ID_MENUITEM_GETHSVCHANNELIMAGE
Command27=ID_MENUITEM_GETHisTOGRAM
Command28=ID_MENUITEM_SMOOTHFILTERING
Command29=ID_MENUITEM_OPENEXDEFAULT
Command30=ID_MENUITEM_FILTER_LAPLACE
Command31=ID_MENUITEM_BINARIZATIONMODE
Command32=ID_MENUITEM_BINARIZATIONMAXENTROPY
Command33=ID_MENUITEM_BINARIZATIONITERATION
Command34=ID_MENUITEM_GETTHRESHOLDIMAGEOTSU
Command35=ID_MENUITEM_GETTHRESHOLDIMAGEMANNAL
Command36=ID_MENUITEM_GETTHRESHOLDIMAGEMANNAL2
Command37=ID_MENUITEM_ROBERTOPERATOR
Command38=ID_MENUITEM_PREWITTOPERATOR
Command39=ID_MENUITEM_GETSEGMENTATIONIMAGESOBEL
Command40=ID_MENUITEM_GETSEGMENTATIONIMAGECANNY
Command41=ID_MENUITEM_GETTHINIMAGEMORPHOLOGY
Command42=ID_MENUITEM_GETTHINIMAGEZHANG
Command43=ID_MENUITEM_GETTHINIMAGEROSEENFELD
Command44=ID_MENUITEM_GETTHINIMAGEDiSTANCE
Command45=ID_MENUITEM_GETTHINIMAGEQTA
Command46=ID_MENUITEM_GETTHINIMAGEHILDITCH
Command47=ID_MENUITEM_GETTHINIMAGEHILDITCH2
Command48=ID_MENUITEM_GETTHINIMAGEPAVLIDIS
Command49=ID_MENUITEM_GETTHINIMAGECLASSIC
Command50=ID_MENUITEM_GETIMAGECLASSIC2
Command51=ID_MENUITEM_GETTHINIMAGEHILDITCH1CLASSIC
Command52=ID_MENUITEM_GETTHINIMAGEHILDITCH2CLASSIC
Command53=ID_MENUITEM_COMPLETEISOLATEPOINT
Command54=ID_MENUITEM_AUTOTEST
Command55=ID_MENUITEM_GETVIDEOINFO
Command56=ID_MENUITEM_OUTPUTALLPOINT
Command57=ID_MENUITEM_GETALLIMIAGE
Command58=ID_MENUITEM_VIDEOGRAY
Command59=ID_MENUITEM_VIDEOROTATE
Command60=ID_MENUITEM_VIDEOREVERSE
Command61=ID_MENUITEM_VIDEOGETRGBCHANNEL
Command62=ID_MENUITEM_VIDEOSMOOTHFILTER
Command63=ID_MENUITEM_VIDEOBINARATIONOSTU
Command64=ID_MENUITEM_VIDEOBINARATIONMAXENTROPY
Command65=ID_MENUITEM_VIDEOBINARIZATIONITERATION
Command66=ID_MENUITEM_VIDEOGETTHINIMAGEMORPHOLOGY
Command67=ID_MENUITEM_VIDEOGETTHINIMAGEZHANG
Command68=ID_MENUITEM_VIDEOGETTHINIMAGEROSENFELD
Command69=ID_MENUITEM_VIDEOGETTHINIMAGEDISTANCE
Command70=ID_MENUITEM_VIDEOCANNYOPERATOR
Command71=ID_MENUITEM_VIDEOSOBELOPERATOR
Command72=ID_MENUITEM_VIDEOROBERTOPERATOR
Command73=ID_MENUITEM_VIDEOPREWITTOPERATOR
Command74=ID_MENUITEM_LPR1_INIT
Command75=ID_MENUITEM_LPR1_HSVGRAY
Command76=ID_MENUITEM_LPR1_MORPHOLOGY
Command77=ID_MENUITEM_LPR1_LOCATIONCOARSE
Command78=ID_MENUITEM_LPR1_GRAY
Command79=ID_MENUITEM_LPR1_THRESHOLD
Command80=ID_MENUITEM_LPR_AUTOTEST
Command81=ID_MENUITEM_VPC_GRAYING
Command82=ID_MENUITEM_VPD_RGB
Command83=ID_MENUITEM_VPC_HSV
Command84=ID_MENUITEM_VPD_MEANFILTERING
Command85=ID_MENUITEM_VeinAutoTest
Command86=ID_MENUITEM_SOYBEANGETGRAYIMAGE
Command87=ID_MENUITEM_SOYBEANGETSMOOTHIMAGE
Command88=ID_MENUITEM_SOYBEANGETTHRESHOLDIMAGEOTSU
Command89=ID_MENUITEM_SOYBEANGETTHRESHOLDIMAGEMANNAL
Command90=ID_MENUITEM_SOYBEANGETTHRESHOLDIMAGEMAXENTROPY
Command91=ID_MENUITEM_SOYBEANGETTHRESHOLDIMAGEITERATOR
Command92=ID_MENUITEM_SOYBEANRUNALLPRETREATMENT
Command93=ID_MENUITEM_SOYBEANRUNALLPRETREATMENTSEGMATATION
Command94=ID_MENUITEM_SOYBEANGETTHINIMAGEMORPHOLOGY
Command95=ID_MENUITEM_SOYBEANGETTHINIMAGEZHANG
Command96=ID_MENUITEM_SOYBEANGETTHINIMAGEROSENFELD
Command97=ID_MENUITEM_SOYBEANGETTHINIMAGEDISTANCE
Command98=ID_MENUITEM_SOYBEANGETSEGMENTATIONIMAGECANNY
Command99=ID_MENUITEM_SOYBEANGETSEGMENTATIONIMAGESOBEL
Command100=ID_MENUITEM_SOYBEANGETSEGMENTATIONIMAGEROBERT
Command101=ID_MENUITEM_SOYBEANGETSEGMENTATIONIMAGEPREWiTT
Command102=ID_MENUITEM_SOYBEANCOMPLETEISOLATIONPOINT
Command103=ID_MENUITEM_SoybeanCompleteEndPoint
Command104=ID_MENUITEM_SOYBEANCOMPLETEMANNAL
Command105=ID_MENUITEM_SOYBEANCOMPLETEAUTO
Command106=ID_MENUITEM_SOYBEANCALCULATEBARCHDATA
Command107=ID_MENUITEM_LICENSEPLATEGETGRAYIMAGE
Command108=ID_MENUITEM_LINCENSEPLATEGETRGBCHANNELIMAGE
Command109=ID_MENUITEM_LICENSEPLATEGETHSVCHANNELIMAGE
Command110=ID_MENUITEM_LICENSEPLATEROBERTOPERATOR
Command111=ID_MENUITEM_LICENSEPLATEPREWITTOPERATOR
Command112=ID_MENUITEM_LicensePlateSobelOperator
Command113=ID_MENUITEM_LICENSEPLATECANNYOPERATOR
Command114=ID_MENUITEM_ZHANGEXTENDPRETREATMENT
Command115=ID_MENUITEM_ZHANGEXTENDZHANG
Command116=ID_MENUITEM_ZHANGEXTENDSINGLEPIXEL
Command117=ID_APP_ABOUT
Command118=ID_MENUITEM_CP_GRAY
Command119=ID_MENUITEM_CP_BINARY
Command120=ID_MENUITEM_CP_SEGMENTATION
CommandCount=120

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

[DLG:IDD_DIALOG_SELECTTHRESHOLD (English (U.S.))]
Type=1
Class=CSelectThresholdDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_THRESHOLD,edit,1350631552
Control5=IDC_RADIO_AES,button,1342308361
Control6=IDC_RADIO_DES,button,1342177289

[CLS:CSelectThresholdDialog]
Type=0
HeaderFile=SelectThresholdDialog.h
ImplementationFile=SelectThresholdDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CSelectRGBChannelDialog]
Type=0
HeaderFile=SelectRGBChannelDialog.h
ImplementationFile=SelectRGBChannelDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RADIO_R

[DLG:IDD_DIALOG_SELECTHSVCHANNEL (English (U.S.))]
Type=1
Class=CSelectHSVChannelDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_RADIO_H,button,1342308361
Control5=IDC_RADIO_S,button,1342177289
Control6=IDC_RADIO_B,button,1342177289

[CLS:CSelectHSVChannelDialog]
Type=0
HeaderFile=SelectHSVChannelDialog.h
ImplementationFile=SelectHSVChannelDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DIALOG_SELECTSIZE (English (U.S.))]
Type=1
Class=CSelectSize
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_SIZE,edit,1350631552

[CLS:CSelectSize]
Type=0
HeaderFile=SelectSize.h
ImplementationFile=SelectSize.cpp
BaseClass=CDialog
Filter=D
LastObject=CSelectSize
VirtualFilter=dWC

[DLG:IDD_DIALOG_SELECTRGBCHANNEL (English (U.S.))]
Type=1
Class=CSelectRGBChannelDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_RADIO_R,button,1342308361
Control5=IDC_RADIO_G,button,1342177289
Control6=IDC_RADIO_B,button,1342177289

[DLG:IDD_DIALOG_SELECTCALSTYLE (English (U.S.))]
Type=1
Class=CSlectCalculateStyleDialog
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_RADIO_X,button,1342308361
Control5=IDC_RADIO_Y,button,1342177289
Control6=IDC_RADIO_MAX,button,1342177289
Control7=IDC_RADIO4,button,1342177289

[CLS:CSlectCalculateStyleDialog]
Type=0
HeaderFile=SlectCalculateStyleDialog.h
ImplementationFile=SlectCalculateStyleDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CSlectCalculateStyleDialog
VirtualFilter=dWC

[DLG:IDD_DIALOG_SELECTROTATE (English (U.S.))]
Type=1
Class=CSelectRotateDialog
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_ANGLE,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_RADIO_CLOCKWISE,button,1342308361
Control7=IDC_RADIO2,button,1342177289

[CLS:CSelectRotateDialog]
Type=0
HeaderFile=SelectRotateDialog.h
ImplementationFile=SelectRotateDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSelectRotateDialog

