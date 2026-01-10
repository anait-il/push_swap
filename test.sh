#!/bin/bash

PUSH_SWAP=./push_swap
CHECKER=./checker_Mac   # or ./checker_Mac
GEN=./gen.py

TESTS=50
COUNT=500
MAX=500

for ((i=1; i<=TESTS; i++)); do
    ARG=$($GEN $COUNT $MAX)

    OPS=$($PUSH_SWAP $ARG)
    RESULT=$(echo "$OPS" | $CHECKER $ARG)
    COUNT_OPS=$(echo "$OPS" | wc -l)

    if [ "$RESULT" = "OK" ]; then
        echo "✅ Test $i: OK | ops = $COUNT_OPS"
    else
        echo "❌ Test $i: KO"
        echo "ARGS: $ARG"
        exit 1
    fi
done
