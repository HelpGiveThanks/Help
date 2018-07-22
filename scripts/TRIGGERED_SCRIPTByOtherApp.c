July 21, 2018 21:35:39 Help.fmp12 - TRIGGERED_SCRIPTByOtherApp -1-
TRIGGERED_SCRIPTByOtherApp
#
#
#Admin tasks.
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#
#Set common variables for going to requested
#layout and column.
Set Variable [ $$layout; Value:MemorySwitch::helpLayoutName ]
Set Variable [ $$anchor; Value:MemorySwitch::helpLayoutObjectName ]
Set Variable [ $$number ]
#When time permits change all the layout
#header conditional formatting to use the
#$$columnLetter variable, instead of the
#$$column variable. I do like the simpler
#variable better, but it the longer version is
#being used by every number graphic on
#every layout, so the longer version wins.
Set Variable [ $$columnLetter; Value:Left ( $$anchor ; 1 ) ]
Set Variable [ $$column; Value:Left ( MemorySwitch::helpLayoutObjectName ; 1 ) ]
Set Variable [ $$highlightOther ]
#
#
#Now go the selected layout and column.
Perform Script [ “CHUNK_scrollHelpToAnchor” ]
#
#
