!ifndef VERSION
  !define VERSION '0.5.28'
!endif

Name "Battletech Character Creator v.${VERSION}"

OutFile "btcc-${VERSION}-setup.exe"
InstallDir $PROGRAMFILES\BtCC

RequestExecutionLevel user


Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

Section "Battletech Character Creator (required)"
  SectionIn RO

  SetOutPath $INSTDIR

  File "btnchrcreator.exe"
  File "QtCore4.dll"
  File "QtGui4.dll"
  File "msvcr100.dll"
  CreateDirectory "$INSTDIR\resource"
  
  SetOutPath $INSTDIR\resource
  File "resource\*.*"
  SetOutPath $INSTDIR

  WriteRegStr HKLM SOFTWARE\BtCC "Install_Dir" "$INSTDIR"

  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\BtCC" "DisplayName" "Battletech Character Creator"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\BtCC" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\BtCC" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\BtCC" "NoRepair" 1
  WriteUninstaller "uninstall.exe"


SectionEnd

Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\BtCC"
  CreateShortCut "$SMPROGRAMS\BtCC\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\BtCC\Battletech Character Creator.lnk" "$INSTDIR\btnchrcreator.exe" "" "$INSTDIR\btnchrcreator.exe" 0
  
SectionEnd


Section "Uninstall"
;  SetShellVarContext all

  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\BtCC"
  DeleteRegKey HKLM SOFTWARE\BtCC

  ; Remove files and uninstaller  
  Delete "$INSTDIR\resource\*.*"
  Delete "$INSTDIR\*.*"


  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\BtCC\*.*"
  RMDir "$SMPROGRAMS\BtCC"
  
  RMDir "$INSTDIR\resource"
  RMDir "$INSTDIR"

SectionEnd
