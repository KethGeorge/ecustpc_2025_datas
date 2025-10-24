rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=5 -tN=20 -nl=3 -nr=7 -tM=20 -ml=3 -mr=7 -dl=1 -dr=20" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=60000 -tN=300000 -nl=3 -nr=7 -tM=300000 -ml=3 -mr=7 -dl=1 -dr=40 test3" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=60000 -tN=300000 -nl=3 -nr=7 -tM=300000 -ml=3 -mr=7 -dl=0 -dr=0 test4" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=60000 -tN=300000 -nl=3 -nr=7 -tM=300000 -ml=3 -mr=7 -dl=0 -dr=0 test5" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=60000 -tN=300000 -nl=3 -nr=7 -tM=300000 -ml=3 -mr=7 -dl=0 -dr=0 test6" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6000 -tN=300000 -nl=30 -nr=70 -tM=300000 -ml=30 -mr=70 -dl=1 -dr=40 test7" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6000 -tN=300000 -nl=30 -nr=70 -tM=300000 -ml=30 -mr=70 -dl=0 -dr=0 test8" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6000 -tN=300000 -nl=30 -nr=70 -tM=300000 -ml=30 -mr=70 -dl=0 -dr=0 test9" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6000 -tN=300000 -nl=30 -nr=70 -tM=300000 -ml=30 -mr=70 -dl=0 -dr=0 test10" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=600 -tN=300000 -nl=300 -nr=700 -tM=300000 -ml=300 -mr=700 -dl=1 -dr=40 test11" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=600 -tN=300000 -nl=300 -nr=700 -tM=300000 -ml=300 -mr=700 -dl=0 -dr=0 test12" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=600 -tN=300000 -nl=300 -nr=700 -tM=300000 -ml=300 -mr=700 -dl=0 -dr=0 test13" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=600 -tN=300000 -nl=300 -nr=700 -tM=300000 -ml=300 -mr=700 -dl=0 -dr=0 test14" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=60 -tN=300000 -nl=3000 -nr=7000 -tM=300000 -ml=3000 -mr=7000 -dl=1 -dr=40 test15" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=60 -tN=300000 -nl=3000 -nr=7000 -tM=300000 -ml=3000 -mr=7000 -dl=0 -dr=0 test16" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=60 -tN=300000 -nl=3000 -nr=7000 -tM=300000 -ml=3000 -mr=7000 -dl=0 -dr=0 test17" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=60 -tN=300000 -nl=3000 -nr=7000 -tM=300000 -ml=3000 -mr=7000 -dl=0 -dr=0 test18" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=300000 -ml=30000 -mr=70000 -dl=1 -dr=40 test19" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=300000 -ml=30000 -mr=70000 -dl=0 -dr=0 test20" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=300000 -ml=30000 -mr=70000 -dl=0 -dr=0 test21" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=3 -tN=300000 -nl=100000 -nr=100000 -tM=300000 -ml=100000 -mr=100000 -dl=0 -dr=0 test23" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=3 -tN=300000 -nl=100000 -nr=100000 -tM=300000 -ml=100000 -mr=100000 -dl=0 -dr=0 test24" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=3 -tN=300000 -nl=100000 -nr=100000 -tM=300000 -ml=100000 -mr=100000 -dl=0 -dr=0 test25" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=3 -tN=300000 -nl=100000 -nr=100000 -tM=300000 -ml=100000 -mr=100000 -dl=0 -dr=0 test26" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6 -tN=30 -nl=3 -nr=7 -tM=300000 -ml=30000 -mr=70000 -dl=1 -dr=40 test27" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6 -tN=30 -nl=3 -nr=7 -tM=300000 -ml=30000 -mr=70000 -dl=0 -dr=0 test28" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6 -tN=30 -nl=3 -nr=7 -tM=300000 -ml=30000 -mr=70000 -dl=0 -dr=0 test29" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=30 -ml=3 -mr=7 -dl=1 -dr=40 test30" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=30 -ml=3 -mr=7 -dl=0 -dr=0 test31" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=30 -ml=3 -mr=7 -dl=0 -dr=0 test32" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\Midnight_Monsoon_Gen1.exe -tc=100000 -tN=300000 -nl=2 -nr=4 -tM=300000 -ml=2 -mr=4 -dl=0 -dr=0 test33" "tests\32" 32
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
call scripts\gen-answer.bat tests\20 tests\20.a "tests" ""
call scripts\gen-answer.bat tests\21 tests\21.a "tests" ""
call scripts\gen-answer.bat tests\22 tests\22.a "tests" ""
call scripts\gen-answer.bat tests\23 tests\23.a "tests" ""
call scripts\gen-answer.bat tests\24 tests\24.a "tests" ""
call scripts\gen-answer.bat tests\25 tests\25.a "tests" ""
call scripts\gen-answer.bat tests\26 tests\26.a "tests" ""
call scripts\gen-answer.bat tests\27 tests\27.a "tests" ""
call scripts\gen-answer.bat tests\28 tests\28.a "tests" ""
call scripts\gen-answer.bat tests\29 tests\29.a "tests" ""
call scripts\gen-answer.bat tests\30 tests\30.a "tests" ""
call scripts\gen-answer.bat tests\31 tests\31.a "tests" ""
call scripts\gen-answer.bat tests\32 tests\32.a "tests" ""
call scripts\gen-answer.bat tests\33 tests\33.a "tests" ""

