July 21, 2018 21:37:45 Help.fmp12 - openTutorialMenuWindow (udpate) -1-
tutorial: openTutorialMenuWindow (udpate)
#
#Admin tasks.
Allow User Abort [ Off ]
Set Error Capture [ On ]
Set Variable [ $$menu; Value:1 ]
#
Set Variable [ $$tutorial; Value:1 ]
Go to Field [ ]
Select Window [ Name: "Tutorial"; Current file ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Tutorial"; Height: Get ( ScreenHeight ); Top: 0; Left: 0; Style: Document; Close: “Yes”; Minimize: “Yes”; Maximize: “Yes”; Zoom Control Area: “Yes”; Resize: “Yes” ]
Go to Layout [ “tutorialGroup” (tutorialGroup) ]
Show All Records
Sort Records [ Keep records in sorted order; Specified Sort Order: tutorialGroup::ModuleName; ascending
tutorialGroup::Name; ascending ]
[ Restore; No dialog ]
Adjust Window
[ Resize to Fit ]
Set Variable [ $width; Value:Get (WindowWidth) ]
Select Window [ Name: "Help"; Current file ]
Move/Resize Window [ Current Window; Height: Get ( ScreenHeight ); Width: Get (ScreenWidth) - $width; Top: 0; Left: $width ]
Select Window [ Name: "Tutorial"; Current file ]
Set Variable [ $$iDeviceScrollButForFirstItem; Value:1 ]
End If
Set Variable [ $$menu ]
