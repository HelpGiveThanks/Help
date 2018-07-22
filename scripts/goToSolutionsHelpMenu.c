July 22, 2018 15:20:28 Help.fmp12 - goToAppHelpMenu -1-
goToAppHelpMenu
Go to Field [ ]
Set Variable [ $$menu; Value:1 ]
Close Window [ Name: "Menu"; Current file ]
New Window [ Name: "Menu"; Style: Document; Close: “Yes”; Minimize: “Yes”; Maximize: “Yes”; Zoom Control Area: “Yes”; Resize: “Yes” ]
Go to Layout [ “menu” (module) ]
Set Variable [ $$menu ]
Adjust Window
[ Resize to Fit ]
Show All Records
Sort Records [ Keep records in sorted order; Specified Sort Order: module::order; ascending
module::name; ascending ]
[ Restore; No dialog ]
