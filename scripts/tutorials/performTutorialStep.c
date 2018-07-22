July 21, 2018 21:38:08 Help.fmp12 - performTutorialStep -1-
tutorial: performTutorialStep
#
#
#Admin tasks.
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#
#Stop this script if other scripts are running.
If [ $$stopScript = 1
or
tutorial::instructionEdit = "" and tutorial::anchor = "" and tutorial::helpNumber = "" ]
Exit Script [ ]
End If
#
#Stop this script and inform the user if
#no tutorial had been selected.
If [ tutorial::layoutName = "" ]
Show Custom Dialog [ Message: "Select a tutorial to do."; Default Button: “OK”, Commit: “Yes” ]
Go to Field [ tutorial::layoutName ]
[ Select/perform ]
Exit Script [ ]
End If
#
#
#If the anchor field has an anchor in it then use
#that, otherwise get the anchor from the
#helpNumber field.
If [ tutorial::anchor ≠ "" ]
Set Variable [ $$anchor; Value:tutorial::anchor ]
Else
#
#The number fields for 4.0 version layouts have
#a letter before each number, whereas 2.0
#version layouts just have a number. Thus
#getting this information is different for each.
If [ tutorial::klayout = "Learn" or tutorial::klayout = "Setup" ]
Set Variable [ $$anchor; Value:Middle ( tutorial::helpNumber ; 2 ; 99 ) ]
Else
Set Variable [ $$anchor; Value:tutorial::helpNumber ]
End If
End If
#
#
#Now get the number that will be highlighted
#on the tutorial and help layouts for this tutorial
#step.
#
#The number fields for 4.0 version layouts have
#a letter before each number, whereas 2.0
#version layouts just have a number. Thus
#getting this information is different for each.
If [ tutorial::klayout = "Learn" or tutorial::klayout = "Setup" ]
Set Variable [ $$helpNumber; Value:Middle ( tutorial::helpNumber ; 2 ; 99 ) ]
Else
Set Variable [ $$helpNumber; Value:tutorial::helpNumber ]
End If
#
#
#Set common variables for this tutorial step.
Set Variable [ $$layout; Value:tutorial::klayout ]
Set Variable [ $$number; Value:Get (RecordNumber) ]
#
#When time permits change all the layout
#header conditional formatting to use the
#$$columnLetter variable, instead of the
#$$column variable. I do like the simpler
#variable better, but it the longer version is
#being used by every number graphic on
#every layout, so the longer version wins.
#
#The number fields for 4.0 version layouts have
#a letter before each number, whereas 2.0
#version layouts just have a number. Thus
#getting this information is different for each.
If [ tutorial::klayout = "Learn" or tutorial::klayout = "Setup" ]
If [ tutorial::helpNumber = "" ]
Set Variable [ $$columnLetter; Value:Left ( tutorial::anchor ; 1 ) ]
Set Variable [ $$column; Value:Left ( tutorial::anchor ; 1 ) ]
Else
Set Variable [ $$columnLetter; Value:Left ( tutorial::helpNumber ; 1 ) ]
Set Variable [ $$column; Value:Left ( tutorial::helpNumber ; 1 ) ]
End If
Else
Set Variable [ $$columnLetter; Value:Left ( $$anchor ; 1 ) ]
Set Variable [ $$column; Value:Left ( $$anchor ; 1 ) ]
End If
Set Variable [ $$highlightOther; Value:tutorial::highlightOtherObject ]
#
#
#Exit all fields, refresh the tutorial window to
#show highlight of current step, and scroll
#window so this step is at the top of the
#window. This allows the user to keep click the
#second step down, like an advance button, so
#they don't have to scroll the window as they
#click thru all the steps in a tutorial.
Go to Field [ ]
Refresh Window
Scroll Window
[ To Selection ]
#
#
#If on a mobile device, only 1 window can be
#viewed at a time. So only perform this next
#step of updating the Help window if the user
#is on a desktop/laptop computer where both
#the tutorial and help windows can been seen
#simultaneously.
If [ Get ( Device ) ≠ 3 and Get ( Device ) ≠ 4 ]
Select Window [ Name: "Help"; Current file ]
Perform Script [ “CHUNK_scrollHelpToAnchor” ]
Select Window [ Name: "Tutorial"; Current file ]
End If
#
#
