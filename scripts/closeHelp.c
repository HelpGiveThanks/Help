July 22, 2018 15:12:44 Help.fmp12 - closeHelp -1-
closeHelp
#
#
#When help is opened it goes to the help screen
#for the solution window the user is on when they click
#the ? mark button. BUT once open, the layoutName
#field become controlled by the Help solution so the
#? mark button in the solutions will return the user to
#the Help solution, but will not change the Help screen
#to match the solution screen that the user is on.
#SO when closing help, this layoutName field is cleared
#so that the next time the user clicks the ? mark button
#it will take them to the Help solution screen for the
#solution screen that they where just on and not the
#last Help screen they where looking at when they
#closed help.
Set Field [ tutorial::layoutName; "" ]
#
#
Set Field [ MemorySwitch::helpAppIsRunning; "" ]
#
#
Close Window [ Current Window ]
Close Window [ Current Window ]
Close Window [ Current Window ]
Close Window [ Current Window ]
Close Window [ Current Window ]
Close Window [ Current Window ]
Close Window [ Current Window ]
Close Window [ Current Window ]
