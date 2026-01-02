#!/bin/bash

ITERATIONS=500
INT_MIN=-2147483648
INT_MAX=2147483647

run_test() {
    local COUNT=$1
    local TEST_NAME=$2
    
    echo "=================================================="
    echo "  RUNNING $TEST_NAME TEST ($ITERATIONS iterations)"
    echo "=================================================="

    > results.txt
    > checks.txt
    > leaks_log.txt
    LEAK_COUNT=0

    for i in $(seq 1 $ITERATIONS); do
        echo -ne "Progress: $i / $ITERATIONS\r"

        ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range($INT_MIN, $INT_MAX), $COUNT))))")

        valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=42 --quiet ./push_swap $ARG > temp_output.txt 2> valgrind_tmp.txt
        
        VALGRIND_EXIT=$?

        cat temp_output.txt | wc -l >> results.txt
        cat temp_output.txt | ./checker_linux $ARG >> checks.txt

        if [ $VALGRIND_EXIT -eq 42 ]; then
            ((LEAK_COUNT++))
            echo "Iteration $i: LEAK DETECTED" >> leaks_log.txt
            cat valgrind_tmp.txt >> leaks_log.txt
            echo "-----------------------------------" >> leaks_log.txt
        fi
    done

    echo -e "\n\n--- $TEST_NAME STATISTICS ---"

    AVG=$(awk '{ total += $1 } END { printf "%.0f", total/NR }' results.txt)
    echo "Average Moves: $AVG"

    MAX=$(sort -nr results.txt | head -1)
    echo "Max Moves:     $MAX"

    MIN=$(sort -n results.txt | head -1)
    echo "Min Moves:     $MIN"

    ERRORS=$(grep -v "OK" checks.txt | wc -l)
    if [ "$ERRORS" -eq 0 ]; then
        echo "Sorting:       PASS (All OK)"
    else
        echo "Sorting:       FAIL ($ERRORS errors found!)"
    fi

    if [ "$LEAK_COUNT" -eq 0 ]; then
        echo "Memory:        PASS (No leaks)"
    else
        echo "Memory:        FAIL ($LEAK_COUNT runs had leaks!)"
        echo "See 'leaks_log.txt' for details."
    fi
    echo ""

    rm results.txt checks.txt temp_output.txt valgrind_tmp.txt leaks_log.txt
}

run_test 100 "STACK 100"
run_test 500 "STACK 500"