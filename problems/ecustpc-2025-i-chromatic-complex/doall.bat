rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=5 -size=0 -lr=20" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=0 -lr=0" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=0 -lr=20" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=0 -lr=40" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=0 -lr=60" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=0 -lr=80" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=1 -lr=0" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=1 -lr=20" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=1 -lr=40" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=1 -lr=60" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=100 -size=1 -lr=80" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=1 -size=2 -lr=0" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=1 -size=2 -lr=20" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=1 -size=2 -lr=40" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=1 -size=2 -lr=60" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\Chromatic_Complex_Gen1.exe -tc=1 -size=2 -lr=80" "tests\17" 17
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

