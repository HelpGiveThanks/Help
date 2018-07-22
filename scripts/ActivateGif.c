July 21, 2018 21:36:33 Help.fmp12 - CHUNK_backToLibrary -1-
CHUNK_backToLibrary
#
#
#Admin tasks.
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#
Select Window [ Name: MemorySwitch::helpAppWindowName[3] ]
Select Window [ Name: MemorySwitch::helpAppWindowName[2] ]
Select Window [ Name: MemorySwitch::helpAppWindowName ]
#
#
If [ Get (LastError) = 112 and MemorySwitch::currentLibraryPath ≠ "" ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (MemorySwitch::currentLibraryPath ; " " ; "%20" ) ;
Substitute ( Substitute ( MemorySwitch::currentLibraryPath ; "file:/" ; "file://" ) ; " " ; "%20" ) ) ]
[ No dialog ]
If [ Get (LastError) = 5 ]
Set Variable [ $$stopRecordLoad; Value:1 ]
New Window [ Name: "library"; Style: Document; Close: “Yes”; Minimize: “Yes”; Maximize: “Yes”; Zoom Control Area: “Yes”; Resize: “Yes” ]
Go to Layout [ “MemorySwitch” (MemorySwitch) ]
Set Variable [ $$stopRecordLoad ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ Get (FoundCount) = 0 ]
#
#These disabled script steps deleted all invalid paths
#to libraries and opened the first path that was valid.
// Open URL [ Substitute ( Substitute ( MemorySwitch::path ; "file:/" ; "file://" ) ; " " ; "%20" ) ]
[ No dialog ]
// Exit Loop If [ Get (LastError) = 0 ]
// Delete Record/Request
[ No dialog ]
// Exit Loop If [ Get (LastError) = 101 ]
Exit Loop If [ MemorySwitch::currentLibraryPath = MemorySwitch::path ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ MemorySwitch::currentLibraryPath = MemorySwitch::path ]
Delete Record/Request
[ No dialog ]
End If
Set Variable [ $found; Value:Get (FoundCount) ]
Close Window [ Current Window ]
If [ $found = 0 ]
Show Custom Dialog [ Message: "There is no library file in memory. Open one up manually, and it will be added to memory and opened when you next click the library button."; Default Button: “OK”, Commit: “No” ]
Else
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" )
& "library/library." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" )
& "library/library." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ) ]
[ No dialog ]
If [ Get (LastError) = 5 ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" )
& "library/library.USR"
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" )
& "library/library.USR"
 ; " " ; "%20" ) ) ]
[ No dialog ]
If [ Get (LastError) = 5 ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" )
& "library/library.USR"
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:///" )
& "library/library.USR"
 ; " " ; "%20" ) ) ]
[ No dialog ]
End If
End If
If [ Get (LastError) = 5 ]
Show Custom Dialog [ Message: "The library you last looked at cannot be opened because its name was changed, the file was moved, or deleted. Open a library file up manually, and it will be added to memory and opened when you next click the library button."; Default Button: “OK”, Commit: “No” ]
End If
End If
End If
Else If [ Get (LastError) = 112 and MemorySwitch::currentLibraryPath = "" ]
Show Custom Dialog [ Message: "There is no library file in memory. Open one up, and it will be added to memory to be opened in when you next click the library button."; Default Button: “OK”, Commit: “No” ]
End If
#
#
#
#
