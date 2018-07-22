July 21, 2018 21:38:26 Help.fmp12 - gofromTutorialToHelp -1-
tutorial: gofromTutorialToHelp
Select Window [ Name: "Help"; Current file ]
If [ Get ( Device ) = 3 or Get ( Device ) = 4 ]
Perform Script [ “CHUNK_scrollHelpToAnchor” ]
End If
