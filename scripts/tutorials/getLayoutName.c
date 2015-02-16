tutorial: getLayoutName
Select Window [ Name: "Help"; Current file ]
Set Variable [ $$layout; Value:Get(LayoutName) ]
Select Window [ Name: "Tutorial"; Current file ]
Set Field [ tutorial::klayout; $$layout ]
