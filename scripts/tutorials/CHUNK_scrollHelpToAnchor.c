July 21, 2018 21:38:37 Help.fmp12 - CHUNK_scrollHelpToAnchor -1-
tutorial: CHUNK_scrollHelpToAnchor
#
#
#Admin tasks.
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#
#Perform bug fix for extra large layouts.
Perform Script [ “fixForLearnLayoutBug” ]
#
#
#If not on the correct layout, then go to it.
If [ Get (LayoutName) ≠ $$layout ]
Go to Layout [ $$layout ]
Set Variable [ $newLayout; Value:1 ]
End If
#
#
#Go the bottom left corner of the layout to
#insure the user's selection will be properly
#scrolled to in the next step.
Go to Object [ Object Name: "bottomLeftCorner" ]
#
#
#If this an mobile device, then pause an little bit
#longer when going to a new layout to insure
#the window is properly scrolled to this bottom-
#left anchor.
If [ $newLayout = 1 and Get ( Device ) = 3 or $newLayout = 1 and Get ( Device ) = 4 ]
Pause/Resume Script [ Duration (seconds): .2 ]
Go to Field [ ]
Go to Object [ Object Name: "bottomLeftCorner" ]
Pause/Resume Script [ Duration (seconds): .2 ]
End If
#
#
#Now implement the pause times to the
#bottom-left anchor and then to the selected
#object leaving more time for mobile devices.
If [ Get ( Device ) = 3 or Get ( Device ) = 4 ]
#The first time in a tutorial sometimes requires
#more time, but more testing is required to
#tweak the amount of time.
If [ $$iDeviceScrollButForFirstItem = 1 ]
Pause/Resume Script [ Duration (seconds): .3 ]
Set Variable [ $$iDeviceScrollButForFirstItem ]
Else
Pause/Resume Script [ Duration (seconds): .3 ]
End If
#
Go to Field [ ]
Go to Object [ Object Name: $$anchor ]
Pause/Resume Script [ Duration (seconds): .3 ]
#
#Desktop/laptop computers require .1 seconds.
Else
Pause/Resume Script [ Duration (seconds): .1 ]
Go to Object [ Object Name: $$anchor ]
Pause/Resume Script [ Duration (seconds): .1 ]
End If
#
#
#Exit the anchor object and refresh the window
#to show conditional formatting changes.
Go to Field [ ]
Refresh Window
#
#
