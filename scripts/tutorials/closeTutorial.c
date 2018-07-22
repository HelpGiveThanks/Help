July 21, 2018 21:38:48 Help.fmp12 - closeTutorial (udpate) -1-
tutorial: closeTutorial (udpate)
Close Window [ Current Window ]
Set Variable [ $width; Value:Get (ScreenWidth) ]
Set Variable [ $$anchor ]
Set Variable [ $$tutorial ]
Set Variable [ $$helpNumber ]
Set Variable [ $$columnLetter ]
Set Variable [ $$highlightOther ]
Select Window [ Name: "Help"; Current file ]
Move/Resize Window [ Current Window; Height: Get ( ScreenHeight ); Width: $width; Top: 0; Left: 0 ]
Refresh Window
