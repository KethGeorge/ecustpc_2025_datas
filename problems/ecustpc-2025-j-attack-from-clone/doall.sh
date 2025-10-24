#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #2"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=100 -d=100 -k=100 Test2" "tests/02" 2
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=100 -d=100 -k=10 Test3" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=100 -d=100 -k=1 Test4" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_2.exe -tc=100 -n=100 -m=100 -d=100 -k=100 Test5" "tests/05" 5
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_2.exe -tc=100 -n=100 -m=100 -d=100 -k=10 Test6" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_2.exe -tc=100 -n=100 -m=100 -d=100 -k=5 Test7" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=100 -k=0 Test8" "tests/08" 8
echo "Generating test #9"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=5 -k=0 Test9" "tests/09" 9
echo "Generating test #10"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=1 -k=0 Test10" "tests/10" 10
echo "Generating test #11"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=5 -d=5 -k=5 Test11" "tests/11" 11
echo "Generating test #12"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_3.exe -tc=100 -n=95 -m=95 -d=95 -k=95 Test12" "tests/12" 12
echo "Generating test #13"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=100 -k=100 Test13" "tests/13" 13
echo "Generating test #14"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=10 -n=100 -m=100 -d=100 -k=100 Test14" "tests/14" 14
echo "Generating test #15"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=1 -n=100 -m=100 -d=100 -k=100 Test15" "tests/15" 15
echo "Generating test #16"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_3.exe -tc=100 -n=98 -m=98 -d=98 -k=98 Test16" "tests/16" 16
echo "Generating test #17"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=5 -d=5 -k=5 Test17" "tests/17" 17
echo "Generating test #18"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=5 -m=5 -d=5 -k=5 Test18" "tests/18" 18
echo "Generating test #19"
scripts/gen-input-via-stdout.sh "wine files/Attack_From_Clone_Gen_1.exe -tc=100 -n=100 -m=100 -d=0 -k=0 Test19" "tests/19" 19
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

