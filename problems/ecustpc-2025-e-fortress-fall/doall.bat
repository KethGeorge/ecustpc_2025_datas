rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=1 -n=5 -lA=-10 -rA=10 -lX=-10 -rX=10 -lY=-10 -rY=10" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=20 -n=7 -lA=-100 -rA=100 -lX=-100 -rX=100 -lY=-100 -rY=100" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=300 -n=1000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=60 -n=5000 -lA=0 -rA=0 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=30 -n=8000 -lA=-1000000 -rA=1000000 -lX=0 -rX=0 -lY=0 -rY=0" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=50 -n=6000 -lA=1 -rA=1000000 -lX=-1000000 -rX=-1000000 -lY=-1000000 -rY=-1000000" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=50 -n=6000 -lA=-1000000 -rA=-1 -lX=1000000 -rX=1000000 -lY=1000000 -rY=1000000" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=40 -n=7000 -lA=-1000000 -rA=1000000 -lX=1000000 -rX=1000000 -lY=1000000 -rY=1000000" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=30 -n=9000 -lA=-1000000 -rA=1000000 -lX=500000 -rX=1000000 -lY=-1000000 -rY=-100000" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=30 -n=8500 -lA=-1000000 -rA=1000000 -lX=-500000 -rX=-100000 -lY=-1000000 -rY=-600000" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=30 -n=7500 -lA=-50 -rA=50 -lX=500000 -rX=500000 -lY=500000 -rY=500000" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=40 -n=6500 -lA=-1000000 -rA=1000000 -lX=0 -rX=0 -lY=777777 -rY=777777" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=40 -n=6500 -lA=-1000000 -rA=1000000 -lX=777777 -rX=777777 -lY=0 -rY=0" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=3 -n=100000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=3 -n=90000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=10000 -n=11 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=50000 -n=5 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=10000 -n=17 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=200 -n=5 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=3 -n=90000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000 test20" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=3 -n=90000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000 test21" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=3 -n=90000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000 test22" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=100000 -n=2 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\Fortress_Fall_Gen1.exe -tc=100000 -n=3 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests\25" 25
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

