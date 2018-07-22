July 21, 2018 21:38:57 Help.fmp12 - makePlainText -1-
tutorial: makePlainText
Set Variable [ $text; Value:TextColorRemove ( TextFontRemove ( TextSizeRemove ( tutorial::instructionEdit ) ) ) ]
Set Field [ tutorial::instructionEdit; $text ]
