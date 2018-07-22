July 22, 2018 15:25:24 Help.fmp12 - rememberLayoutUserIsOn -1-
rememberLayoutUserIsOn
#
#
If [ $$menu = 1 ]
Exit Script [ ]
End If
#
#
Set Variable [ $$layout; Value:Get (LayoutName) ]
Set Field [ MemorySwitch::helpLayoutName; Get (LayoutName) ]
If [ LeftValues ( tutorial::layoutName ; 1 ) ≠ Get (LayoutName) & ¶ ]
Set Variable [ $name; Value:tutorial::layoutName ]
Set Field [ tutorial::layoutName; Get (LayoutName) & ¶ & $name ]
End If
#
#Help 2.0 Messages
#REFERENCE
If [ Get (LayoutName) = "Reference" and $$help2message_Reference = "" ]
Show Custom Dialog [ Message: "Help shown (version 2.0) is useful for understanding how the improved reference section, version 4.0d works. A help update will be created when time permits."; Default Button: “OK”, Commit: “Yes” ]
Set Variable [ $$help2message_Reference; Value:1 ]
Set Variable [ $$help2message; Value:1 ]
End If
#TEST
If [ Get (LayoutName) = "Test" and $$help2message_Test = "" ]
Show Custom Dialog [ Message: "Help shown (version 2.0) is useful for understanding how the improved test-template, test, and report section, version 4.0d works. A help update will be created when time permits. "; Default Button: “OK”, Commit: “Yes” ]
Set Variable [ $$help2message_Test; Value:1 ]
Set Variable [ $$help2message; Value:1 ]
End If
#TIMER
If [ Get (LayoutName) = "Timer" and $$help2message_Timer = "" ]
Show Custom Dialog [ Message: "Help shown (version 2.0) is useful for understanding how the improved timer section, version 3.2d works. A help update will be created when time permits. "; Default Button: “OK”, Commit: “Yes” ]
Set Variable [ $$help2message_Timer; Value:1 ]
Set Variable [ $$help2message; Value:1 ]
End If
#TIMER EDIT
If [ Get (LayoutName) = "Timer Edit" and $$help2message_TimerEdit = "" ]
Show Custom Dialog [ Message: "Help shown (version 2.0) is useful for understanding how the improved timer-edit section, version 3.2d works. A help update will be created when time permits. "; Default Button: “OK”, Commit: “Yes” ]
Set Variable [ $$help2message_TimerEdit; Value:1 ]
Set Variable [ $$help2message; Value:1 ]
End If
#SPECIFIC ACTION
If [ Get (LayoutName) = "Specific Action" and $$help2message_SpecificAction = "" ]
Show Custom Dialog [ Message: "Help shown (version 2.0) is useful for understanding how the improved specific action section, version 3.2d works. A help update will be created when time permits. "; Default Button: “OK”, Commit: “Yes” ]
Set Variable [ $$help2message_SpecificAction; Value:1 ]
Set Variable [ $$help2message; Value:1 ]
End If
#
#Show this message about any of the above
#messages only showing up once per session,
#only once per session.
If [ $$help2message = 1 and $$help3message = "" ]
Show Custom Dialog [ Message: "Help version 2.0 messages show up once per session. Restart help to see them again."; Default Button: “OK”, Commit: “Yes” ]
Set Variable [ $$help3message; Value:1 ]
End If
#
#
If [ Get (LayoutName) = "Library Story" ]
Set Variable [ $$Anchor ]
Set Variable [ $$Story ]
End If
#
#
