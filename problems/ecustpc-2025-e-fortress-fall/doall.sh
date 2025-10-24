#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #2"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=1 -n=5 -lA=-10 -rA=10 -lX=-10 -rX=10 -lY=-10 -rY=10" "tests/02" 2
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=20 -n=7 -lA=-100 -rA=100 -lX=-100 -rX=100 -lY=-100 -rY=100" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=300 -n=1000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=60 -n=5000 -lA=0 -rA=0 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/05" 5
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=30 -n=8000 -lA=-1000000 -rA=1000000 -lX=0 -rX=0 -lY=0 -rY=0" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=50 -n=6000 -lA=1 -rA=1000000 -lX=-1000000 -rX=-1000000 -lY=-1000000 -rY=-1000000" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=50 -n=6000 -lA=-1000000 -rA=-1 -lX=1000000 -rX=1000000 -lY=1000000 -rY=1000000" "tests/08" 8
echo "Generating test #9"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=40 -n=7000 -lA=-1000000 -rA=1000000 -lX=1000000 -rX=1000000 -lY=1000000 -rY=1000000" "tests/09" 9
echo "Generating test #10"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=30 -n=9000 -lA=-1000000 -rA=1000000 -lX=500000 -rX=1000000 -lY=-1000000 -rY=-100000" "tests/10" 10
echo "Generating test #11"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=30 -n=8500 -lA=-1000000 -rA=1000000 -lX=-500000 -rX=-100000 -lY=-1000000 -rY=-600000" "tests/11" 11
echo "Generating test #12"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=30 -n=7500 -lA=-50 -rA=50 -lX=500000 -rX=500000 -lY=500000 -rY=500000" "tests/12" 12
echo "Generating test #13"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=40 -n=6500 -lA=-1000000 -rA=1000000 -lX=0 -rX=0 -lY=777777 -rY=777777" "tests/13" 13
echo "Generating test #14"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=40 -n=6500 -lA=-1000000 -rA=1000000 -lX=777777 -rX=777777 -lY=0 -rY=0" "tests/14" 14
echo "Generating test #15"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=3 -n=100000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/15" 15
echo "Generating test #16"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=3 -n=90000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/16" 16
echo "Generating test #17"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=10000 -n=11 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/17" 17
echo "Generating test #18"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=50000 -n=5 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/18" 18
echo "Generating test #19"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=10000 -n=17 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/19" 19
echo "Generating test #20"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=200 -n=5 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/20" 20
echo "Generating test #21"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=3 -n=90000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000 test20" "tests/21" 21
echo "Generating test #22"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=3 -n=90000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000 test21" "tests/22" 22
echo "Generating test #23"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=3 -n=90000 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000 test22" "tests/23" 23
echo "Generating test #24"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=100000 -n=2 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/24" 24
echo "Generating test #25"
scripts/gen-input-via-stdout.sh "wine files/Fortress_Fall_Gen1.exe -tc=100000 -n=3 -lA=-1000000 -rA=1000000 -lX=-1000000 -rX=1000000 -lY=-1000000 -rY=1000000" "tests/25" 25
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

