#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #2"
scripts/gen-input-via-stdout.sh "wine files/Time_Trouble_Gen1.exe -n=1" "tests/02" 2
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "wine files/Time_Trouble_Gen1.exe -n=10000" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/Time_Trouble_Gen2.exe -n=10000 test1" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "wine files/Time_Trouble_Gen2.exe -n=10000 test1 gen2" "tests/05" 5
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

