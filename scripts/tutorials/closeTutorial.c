tutorial: closeTutorial
Close Window [ Current Window ]
Set Variable [ $width; Value:Get (ScreenWidth) ]
Set Variable [ $$helpNumber ]
Set Variable [ $$anchor ]
Select Window [ Name: "Help"; Current file ]
Move/Resize Window [ Current Window; Height: Get ( ScreenHeight ); Width: $width; Top: 0; Left: 0 ]
