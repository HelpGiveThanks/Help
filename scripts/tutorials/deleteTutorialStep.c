July 21, 2018 21:39:20 Help.fmp12 - deleteTutorialStep -1-
tutorial: deleteTutorialStep
Go to Field [ ]
Set Variable [ $delete; Value:Get (RecordNumber) ]
Refresh Window
Show Custom Dialog [ Message: "Delete instruction " & Get (RecordNumber) & " ?"; Default Button: “Cancel”, Commit: “Yes”; Button 2: “OK”, Commit: “No” ]
If [ Get ( LastMessageChoice ) = 1 ]
Set Variable [ $delete ]
Refresh Window
Exit Script [ ]
End If
Set Variable [ $delete ]
Refresh Window
Delete Record/Request
[ No dialog ]
Sort Records [ Keep records in sorted order; Specified Sort Order: tutorial::kTutorial; ascending
tutorial::number; ascending ]
[ Restore; No dialog ]
Go to Field [ ]
New Window [ Style: Document; Close: “Yes”; Minimize: “Yes”; Maximize: “Yes”; Zoom Control Area: “Yes”; Resize: “Yes” ]
Go to Record/Request/Page
[ Last ]
Loop
Set Field [ tutorial::number; Get (RecordNumber) ]
Go to Record/Request/Page
[ Previous; Exit after last ]
End Loop
Close Window [ Current Window ]
