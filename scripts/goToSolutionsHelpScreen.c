July 21, 2018 21:37:10 Help.fmp12 - gotoMenu  -1-
gotoMenu
Set Variable [ $$layout; Value:Trim ( module::name ) ]
Set Field [ MemorySwitch::helpLayoutName; $$layout ]
Close Window [ Name: "Menu"; Current file ]
Go to Layout [ $$layout ]
Pause/Resume Script [ Duration (seconds): .1 ]
Omit Multiple Records [ Get (FoundCount) - 1 ]
[ No dialog ]
