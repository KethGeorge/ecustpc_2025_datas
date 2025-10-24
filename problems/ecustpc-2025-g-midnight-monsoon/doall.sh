#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #2"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=5 -tN=20 -nl=3 -nr=7 -tM=20 -ml=3 -mr=7 -dl=1 -dr=20" "tests/02" 2
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=60000 -tN=300000 -nl=3 -nr=7 -tM=300000 -ml=3 -mr=7 -dl=1 -dr=40 test3" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=60000 -tN=300000 -nl=3 -nr=7 -tM=300000 -ml=3 -mr=7 -dl=0 -dr=0 test4" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=60000 -tN=300000 -nl=3 -nr=7 -tM=300000 -ml=3 -mr=7 -dl=0 -dr=0 test5" "tests/05" 5
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=60000 -tN=300000 -nl=3 -nr=7 -tM=300000 -ml=3 -mr=7 -dl=0 -dr=0 test6" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6000 -tN=300000 -nl=30 -nr=70 -tM=300000 -ml=30 -mr=70 -dl=1 -dr=40 test7" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6000 -tN=300000 -nl=30 -nr=70 -tM=300000 -ml=30 -mr=70 -dl=0 -dr=0 test8" "tests/08" 8
echo "Generating test #9"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6000 -tN=300000 -nl=30 -nr=70 -tM=300000 -ml=30 -mr=70 -dl=0 -dr=0 test9" "tests/09" 9
echo "Generating test #10"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6000 -tN=300000 -nl=30 -nr=70 -tM=300000 -ml=30 -mr=70 -dl=0 -dr=0 test10" "tests/10" 10
echo "Generating test #11"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=600 -tN=300000 -nl=300 -nr=700 -tM=300000 -ml=300 -mr=700 -dl=1 -dr=40 test11" "tests/11" 11
echo "Generating test #12"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=600 -tN=300000 -nl=300 -nr=700 -tM=300000 -ml=300 -mr=700 -dl=0 -dr=0 test12" "tests/12" 12
echo "Generating test #13"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=600 -tN=300000 -nl=300 -nr=700 -tM=300000 -ml=300 -mr=700 -dl=0 -dr=0 test13" "tests/13" 13
echo "Generating test #14"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=600 -tN=300000 -nl=300 -nr=700 -tM=300000 -ml=300 -mr=700 -dl=0 -dr=0 test14" "tests/14" 14
echo "Generating test #15"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=60 -tN=300000 -nl=3000 -nr=7000 -tM=300000 -ml=3000 -mr=7000 -dl=1 -dr=40 test15" "tests/15" 15
echo "Generating test #16"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=60 -tN=300000 -nl=3000 -nr=7000 -tM=300000 -ml=3000 -mr=7000 -dl=0 -dr=0 test16" "tests/16" 16
echo "Generating test #17"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=60 -tN=300000 -nl=3000 -nr=7000 -tM=300000 -ml=3000 -mr=7000 -dl=0 -dr=0 test17" "tests/17" 17
echo "Generating test #18"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=60 -tN=300000 -nl=3000 -nr=7000 -tM=300000 -ml=3000 -mr=7000 -dl=0 -dr=0 test18" "tests/18" 18
echo "Generating test #19"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=300000 -ml=30000 -mr=70000 -dl=1 -dr=40 test19" "tests/19" 19
echo "Generating test #20"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=300000 -ml=30000 -mr=70000 -dl=0 -dr=0 test20" "tests/20" 20
echo "Generating test #21"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=300000 -ml=30000 -mr=70000 -dl=0 -dr=0 test21" "tests/21" 21
echo "Generating test #22"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=3 -tN=300000 -nl=100000 -nr=100000 -tM=300000 -ml=100000 -mr=100000 -dl=0 -dr=0 test23" "tests/22" 22
echo "Generating test #23"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=3 -tN=300000 -nl=100000 -nr=100000 -tM=300000 -ml=100000 -mr=100000 -dl=0 -dr=0 test24" "tests/23" 23
echo "Generating test #24"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=3 -tN=300000 -nl=100000 -nr=100000 -tM=300000 -ml=100000 -mr=100000 -dl=0 -dr=0 test25" "tests/24" 24
echo "Generating test #25"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=3 -tN=300000 -nl=100000 -nr=100000 -tM=300000 -ml=100000 -mr=100000 -dl=0 -dr=0 test26" "tests/25" 25
echo "Generating test #26"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6 -tN=30 -nl=3 -nr=7 -tM=300000 -ml=30000 -mr=70000 -dl=1 -dr=40 test27" "tests/26" 26
echo "Generating test #27"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6 -tN=30 -nl=3 -nr=7 -tM=300000 -ml=30000 -mr=70000 -dl=0 -dr=0 test28" "tests/27" 27
echo "Generating test #28"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6 -tN=30 -nl=3 -nr=7 -tM=300000 -ml=30000 -mr=70000 -dl=0 -dr=0 test29" "tests/28" 28
echo "Generating test #29"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=30 -ml=3 -mr=7 -dl=1 -dr=40 test30" "tests/29" 29
echo "Generating test #30"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=30 -ml=3 -mr=7 -dl=0 -dr=0 test31" "tests/30" 30
echo "Generating test #31"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=6 -tN=300000 -nl=30000 -nr=70000 -tM=30 -ml=3 -mr=7 -dl=0 -dr=0 test32" "tests/31" 31
echo "Generating test #32"
scripts/gen-input-via-stdout.sh "wine files/Midnight_Monsoon_Gen1.exe -tc=100000 -tN=300000 -nl=2 -nr=4 -tM=300000 -ml=2 -mr=4 -dl=0 -dr=0 test33" "tests/32" 32
echo ""
echo "Generating answer for test #1"
scripts/gen-answer.sh tests/01 tests/01.a "tests" ""
echo ""
echo "Generating answer for test #2"
scripts/gen-answer.sh tests/02 tests/02.a "tests" ""
echo ""
echo "Generating answer for test #3"
scripts/gen-answer.sh tests/03 tests/03.a "tests" ""
echo ""
echo "Generating answer for test #4"
scripts/gen-answer.sh tests/04 tests/04.a "tests" ""
echo ""
echo "Generating answer for test #5"
scripts/gen-answer.sh tests/05 tests/05.a "tests" ""
echo ""
echo "Generating answer for test #6"
scripts/gen-answer.sh tests/06 tests/06.a "tests" ""
echo ""
echo "Generating answer for test #7"
scripts/gen-answer.sh tests/07 tests/07.a "tests" ""
echo ""
echo "Generating answer for test #8"
scripts/gen-answer.sh tests/08 tests/08.a "tests" ""
echo ""
echo "Generating answer for test #9"
scripts/gen-answer.sh tests/09 tests/09.a "tests" ""
echo ""
echo "Generating answer for test #10"
scripts/gen-answer.sh tests/10 tests/10.a "tests" ""
echo ""
echo "Generating answer for test #11"
scripts/gen-answer.sh tests/11 tests/11.a "tests" ""
echo ""
echo "Generating answer for test #12"
scripts/gen-answer.sh tests/12 tests/12.a "tests" ""
echo ""
echo "Generating answer for test #13"
scripts/gen-answer.sh tests/13 tests/13.a "tests" ""
echo ""
echo "Generating answer for test #14"
scripts/gen-answer.sh tests/14 tests/14.a "tests" ""
echo ""
echo "Generating answer for test #15"
scripts/gen-answer.sh tests/15 tests/15.a "tests" ""
echo ""
echo "Generating answer for test #16"
scripts/gen-answer.sh tests/16 tests/16.a "tests" ""
echo ""
echo "Generating answer for test #17"
scripts/gen-answer.sh tests/17 tests/17.a "tests" ""
echo ""
echo "Generating answer for test #18"
scripts/gen-answer.sh tests/18 tests/18.a "tests" ""
echo ""
echo "Generating answer for test #19"
scripts/gen-answer.sh tests/19 tests/19.a "tests" ""
echo ""
echo "Generating answer for test #20"
scripts/gen-answer.sh tests/20 tests/20.a "tests" ""
echo ""
echo "Generating answer for test #21"
scripts/gen-answer.sh tests/21 tests/21.a "tests" ""
echo ""
echo "Generating answer for test #22"
scripts/gen-answer.sh tests/22 tests/22.a "tests" ""
echo ""
echo "Generating answer for test #23"
scripts/gen-answer.sh tests/23 tests/23.a "tests" ""
echo ""
echo "Generating answer for test #24"
scripts/gen-answer.sh tests/24 tests/24.a "tests" ""
echo ""
echo "Generating answer for test #25"
scripts/gen-answer.sh tests/25 tests/25.a "tests" ""
echo ""
echo "Generating answer for test #26"
scripts/gen-answer.sh tests/26 tests/26.a "tests" ""
echo ""
echo "Generating answer for test #27"
scripts/gen-answer.sh tests/27 tests/27.a "tests" ""
echo ""
echo "Generating answer for test #28"
scripts/gen-answer.sh tests/28 tests/28.a "tests" ""
echo ""
echo "Generating answer for test #29"
scripts/gen-answer.sh tests/29 tests/29.a "tests" ""
echo ""
echo "Generating answer for test #30"
scripts/gen-answer.sh tests/30 tests/30.a "tests" ""
echo ""
echo "Generating answer for test #31"
scripts/gen-answer.sh tests/31 tests/31.a "tests" ""
echo ""
echo "Generating answer for test #32"
scripts/gen-answer.sh tests/32 tests/32.a "tests" ""
echo ""
echo "Generating answer for test #33"
scripts/gen-answer.sh tests/33 tests/33.a "tests" ""
echo ""

