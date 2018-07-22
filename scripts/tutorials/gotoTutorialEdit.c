July 21, 2018 21:39:08 Help.fmp12 - gotoTutorialEdit -1-
tutorial: gotoTutorialEdit
If [ Get ( AccountName ) = "admin" ]
Go to Layout [ “tutorialEdit” (tutorial) ]
Scroll Window
[ End ]
Sort Records [ Keep records in sorted order; Specified Sort Order: tutorial::kTutorial; ascending
tutorial::number; ascending ]
[ Restore; No dialog ]
Refresh Window
End If
