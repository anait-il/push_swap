#!/usr/bin/env python3
import random
import sys

if len(sys.argv) != 3:
    print("Usage: ./gen.py <count> <max_value>")
    sys.exit(1)

count = int(sys.argv[1])
max_val = int(sys.argv[2])

nums = random.sample(range(-max_val, max_val + 1), count)
print(" ".join(map(str, nums)))
