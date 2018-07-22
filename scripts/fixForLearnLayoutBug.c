July 21, 2018 21:37:33 Help.fmp12 - fixForLearnLayoutBug -1-
fixForLearnLayoutBug
#
#
If [ $$menu = 1 ]
Exit Script [ ]
End If
#
#
#The learn layout seems to long, and due to
#this a bug prevents FileMaker from showing
#the layout unless the window size is
#adjusted first.
Set Variable [ $width; Value:Get (WindowWidth) ]
Set Variable [ $height; Value:Get (WindowHeight) ]
Move/Resize Window [ Current Window; Height: $height - 1; Width: $width -1 ]
Pause/Resume Script [ Duration (seconds): .1 ]
Move/Resize Window [ Current Window; Height: $height + 1; Width: $width + 1 ]
