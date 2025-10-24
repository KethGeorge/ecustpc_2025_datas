rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=100 -d=100 -k=100 Test2" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=100 -d=100 -k=10 Test3" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=100 -d=100 -k=1 Test4" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_2.exe -tc=100 -n=100 -m=100 -d=100 -k=100 Test5" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_2.exe -tc=100 -n=100 -m=100 -d=100 -k=10 Test6" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_2.exe -tc=100 -n=100 -m=100 -d=100 -k=5 Test7" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=100 -k=0 Test8" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=5 -k=0 Test9" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=1 -k=0 Test10" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=5 -d=5 -k=5 Test11" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_3.exe -tc=100 -n=95 -m=95 -d=95 -k=95 Test12" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=100 -k=100 Test13" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=10 -n=100 -m=100 -d=100 -k=100 Test14" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=1 -n=100 -m=100 -d=100 -k=100 Test15" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_3.exe -tc=100 -n=98 -m=98 -d=98 -k=98 Test16" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=5 -d=5 -k=5 Test17" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=5 -d=5 -k=5 Test18" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=0 -k=0 Test19" "tests\19" 19
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
call scripts\gen-answer.bat tests\11 tests\11.a "tests" ""
call scripts\gen-answer.bat tests\12 tests\12.a "tests" ""
call scripts\gen-answer.bat tests\13 tests\13.a "tests" ""
call scripts\gen-answer.bat tests\14 tests\14.a "tests" ""
call scripts\gen-answer.bat tests\15 tests\15.a "tests" ""
call scripts\gen-answer.bat tests\16 tests\16.a "tests" ""
call scripts\gen-answer.bat tests\17 tests\17.a "tests" ""
call scripts\gen-answer.bat tests\18 tests\18.a "tests" ""
call scripts\gen-answer.bat tests\19 tests\19.a "tests" ""

