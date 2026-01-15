*This project has been created as part of the 42 curriculum by anait-il.*

# push_swap

## Description

**push_swap** is an algorithmic project from the 42 curriculum whose goal is to sort a stack of integers using a limited set of operations and the smallest possible number of moves.

The program takes a list of integers as arguments, stores them in a stack (stack A), and sorts them in ascending order using an auxiliary stack (stack B). Only predefined operations are allowed, making the project a strong exercise in algorithm optimization, data structures, and problem-solving.

The challenge lies not only in sorting correctly, but in choosing efficient strategies to minimize the number of operations.

## Instructions

### Requirements

- Operating system: Linux or macOS  
- Compiler: `gcc` or `clang`
- Make

### Compilation

To compile the project, run:

```
make
```
### Execution

Run the program with a list of integers as arguments:

```
/.push_swap 3 1 2
```

The program will output a sequence of instructions to standard output, such as:
```
sa
ra
```

### Cleaning

Remove object files:
```
make clean
```
Remove object files and executable:
```
make fclean
```
Recompile everything:
```
make re
```

## Bonus – Checker

The bonus part of the project implements a **checker** program used to validate the correctness of the instructions produced by `push_swap`.

### Description

The `checker` program takes the same list of integers as `push_swap` as arguments.  
It then reads a sequence of operations from standard input and applies them to the stacks.

At the end of execution:
- If stack A is sorted in ascending order **and** stack B is empty, `checker` prints `OK`
- Otherwise, it prints `KO`
- If an invalid instruction is encountered, it prints `Error`

### Compilation

To compile  `checker`:

```
make bonus
```

### checker (bonus)

```
./checker 4 2 7 1 3
```

### Allowed Instructions

The following operations are allowed to manipulate the stacks:

| Instruction | Description |
|------------|-------------|
| `sa` | Swap the first two elements at the top of stack **a** |
| `sb` | Swap the first two elements at the top of stack **b** |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the top element from stack **b** to stack **a** |
| `pb` | Push the top element from stack **a** to stack **b** |
| `ra` | Rotate stack **a** upwards (first element becomes last) |
| `rb` | Rotate stack **b** upwards (first element becomes last) |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack **a** (last element becomes first) |
| `rrb` | Reverse rotate stack **b** (last element becomes first) |
| `rrr` | Perform `rra` and `rrb` simultaneously |

These are the only operations permitted to sort the stack.

Output:

- OK if the stack is correctly sorted

- KO otherwise

## Resources

- 42 subject PDF: push_swap

- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)