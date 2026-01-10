*This project has been created as part of the 42 curriculum by oused-da.*

# Push_swap

## Description

### Overview
**Push_swap** is a project that involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for optimized data sorting.

The project consists of two programs:
1.  **push_swap** (Mandatory): Calculates and displays the smallest list of instructions to sort the integer arguments received.
2.  **checker** (Bonus): Takes integer arguments and reads instructions on the standard input. It executes them and checks if the stack is sorted.

The allowable operations are:
* `sa`, `sb`, `ss`: Swap the first two elements of a stack.
* `pa`, `pb`: Push the top element from one stack to another.
* `ra`, `rb`, `rr`: Rotate the stack (first element becomes last).
* `rra`, `rrb`, `rrr`: Reverse rotate the stack (last element becomes first).

### Algorithm Strategy: The "Butterfly" Approach
The project utilizes a **Chunk-based Sorting Strategy** (often called the Butterfly algorithm) optimized for `push_swap`'s specific constraints:
1.  **Indexing:** First, all values are mapped to their rank (0 to N-1) to simplify comparisons.
2.  **Chunking (A to B):** We define a dynamic range (chunk size). We scan Stack A and push elements that fall within `current_index` and `current_index + range` to Stack B.
    * If the element is in the *lower half* of the range, we rotate Stack B (`rb`).
    * This creates a distribution in Stack B where the largest elements end up near the top or bottom, forming a "butterfly" shape.
3.  **Return (B to A):** We simply push elements back to Stack A, always selecting the current maximum available in B to ensure Stack A is sorted.

## Instructions

### Compilation

This project includes a Makefile that handles compilation for both the mandatory and bonus parts.

* To compile the **push_swap** program:
    ```bash
    make
    ```

* To compile the **checker** program (bonus):
    ```bash
    make bonus
    ```

* To clean object files: `make clean`
* To clean everything (executables + objects): `make fclean`

### Execution

#### Mandatory Part (push_swap)
Run the program with a list of integers as arguments:
```bash
./push_swap 2 1 3 6 5 8
```
*Output: A list of operations separated by newlines.*

#### Bonus Part (checker)
The checker waits for instructions on Standard Input. You can pipe the output of push_swap into it:
```Bash
./push_swap 4 5 26 7 8 2 1 3 | ./checker 4 5 26 7 8 2 1 3
```
*Output: `OK` if sorted, `KO` if not, or `Error` if inputs are invalid.*

You can also run it manually:
```Bash
./checker 3 2 1
sa
ra
(Press CTRL+D)
```
## Resources

### References & Tools
* **Peer Contribution:** Special thanks to **aamajjou** for explaining the core concepts and logic of the project.
* **AI Assistance:** AI (Gemini) was consulted strictly for theoretical explanations of sorting algorithms to aid conceptual understanding.