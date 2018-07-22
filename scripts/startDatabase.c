July 21, 2018 21:35:12 Help.fmp12 - startDatabase -1-
startDatabase
#
#
#Admin tasks.
Allow User Abort [ Off ]
Set Error Capture [ On ]
Show/Hide Text Ruler
[ Hide ]
Show/Hide Toolbars
[ Lock; Hide ]
#
Set Variable [ $$anchor ]
Set Variable [ $$tutorial ]
Set Variable [ $$helpNumber ]
Set Variable [ $$columnLetter ]
Set Variable [ $$highlightOther ]
Set Variable [ $$help2message ]
Set Variable [ $$help3message ]
Set Variable [ $$help2message_Test ]
Set Variable [ $$help2message_Timer ]
Set Variable [ $$help2message_TimerEdit ]
Set Variable [ $$help2message_Reference ]
Set Variable [ $$help2message_SpecificAction ]
#
#
#Report version number to Memory Switch Table.
Set Field [ MemorySwitch::versionHelp; tutorial::version ]
Set Variable [ $$layout; Value:MemorySwitch::helpLayoutName ]
#
#Set name of window to help and size to fit window.
Set Window Title [ Current Window; New Title: "Help" ]
Go to Layout [ MemorySwitch::helpLayoutName ]
Adjust Window
[ Resize to Fit ]
If [ Get (LayoutTableName) = "layout" ]
Delete All Records
[ No dialog ]
New Record/Request
End If
#
#Check if database is being started by administrator.
#If it is then show admin tools.
If [ Get ( AccountName ) = "admin" ]
Set Variable [ $$admin; Value:1 ]
Show/Hide Toolbars
[ Hide ]
End If
#
#If there is no pause the script fails to work.
Pause/Resume Script [ Duration (seconds): .1 ]
Adjust Window
[ Resize to Fit ]
Adjust Window
[ Maximize ]
#
#
#Let other Apps know that the help app
#is running.
Set Field [ MemorySwitch::helpAppIsRunning; 1 ]
#
#
#Set common variables for going to requested
#layout and column.
If [ MemorySwitch::helpLayoutName = "" ]
Set Variable [ $$layout; Value:"Library Story" ]
Else
Set Variable [ $$layout; Value:MemorySwitch::helpLayoutName ]
End If
#
If [ Get ( LayoutName ) = "Library Story" ]
Set Variable [ $$anchor; Value:"A" ]
Set Variable [ $$highlightOther ]
Else If [ MemorySwitch::helpLayoutObjectName = "" and Get ( LayoutName ) ≠ "Library Story" ]
Set Variable [ $$anchor; Value:"A" ]
Set Variable [ $$columnHeader ]
Else
Set Variable [ $$anchor; Value:MemorySwitch::helpLayoutObjectName ]
Set Variable [ $$column; Value:Left ( MemorySwitch::helpLayoutObjectName ; 1 ) ]
End If
#
#
#Now go the selected layout and column.
Perform Script [ “CHUNK_scrollHelpToAnchor” ]
If [ Get ( LayoutName ) = "Library Story" ]
Set Variable [ $$anchor ]
Refresh Window
End If
#
#
