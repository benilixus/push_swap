*This project has been created as part of the 42 curriculum by mel-wahm*

# Description
- The main point of this project is to sort in ascending order numbers into one stack. To do so you have the following operations at your disposal.
- This project focuses on: Algorithmic thinking, optimization under constraints and clean C implementation and memory management

### Operations:
- Swap (sa, sb, ss): Flips the top two elements of one or both stacks.
- Push (pa, pb): Moves the top element from one stack to the top of the other.
- Rotate (ra, rb, rr): Shifts elements up, the top element moves to the bottom.
- Reverse Rotate (rra, rrb, rrr): Shifts elements down, the bottom element moves to the top.

### Score:
- To get a full score, out program should successfully sort 100 numbers under 700 operations, and
500 numbers under 5500 operations.

# Instructions

**Program**
- To compile this project, run:
```bash
make
```
- This will generate an executable **push_swap** that can be used like this:
```bash
./push_swap <list_of_integers>
```
- The program will output the list of operations it used to sort the given list of integers.
- **Example:**
```c
./push_swap 3 2 5 1 4
rra
rra
pb
ra
ra
pb
sa
rra
pa
pa
```

**Checker**
- We can also use the provided checker_linux to make sure that our program works correctly.
- **Usage example:**
```c
./push_swap 3 2 5 1 4 | ./checker_linux  3 2 5 1 4
OK
```
- It prints OK if the program sorts the numbers correctly, prints KO if the numbers are not correctly sorted, and Error in case an Error happen (bad input , Overflow...).

**Cleaning**
```bash
make clean   # removes object files
make fclean  # removes object files and executable
make re      # compiles everything from scratch
```

# Algorithm Choice

**Chunks Method :**
	
	
For this project, I implemented the chunks method, which is a commonly used and efficient strategy for sorting numbers in push_swap.
This implementation of push_swap is based on a dynamic chunking strategy combined with directional rotations to minimize operations while transferring elements between stacks.

### Overview:

**PHASE 1:** Pushing the numbers to B:

***
- I used a lot of tweaks in this algorithm to satisfy the conditions of getting a full score, for example, I used a condition (let's call it the hourglass), which rotates the stack B if the head is a small number (eventually bigger numbers will also be included as the program goes), note that the number is compared to a variable that increments as the program goes, so the numbers do not need to be small all the time.

- The point of this tool is to make the small numbers hide in the middle of stack B, and the bigger numbers tends to the upper and lower side of the stack.

- To make things easier for me, I implemented a function called indexing(stack), which gives every node of our stack an index determining its rank in the stack, in an ascending order (the node with the smallest number has index 0, and the node with the highest numbers has the index n - 1).

- The dynamic part of this algorithm comes with the change of the chunk size, as it does not stay constant the whole runtime of the program (technically it doesnt change, but im comparing my numbers with chucksize + i, i being a varibale), and I did this to also compare the smalll numbers with i and decide which ones to move to the bottom of b.

- After implementing this algorithm we get a stack B with a shape that looks like an hourglass (or a butterfly), which will make the biggers numbers closer to the head of B, as we know, the bigger numbers should be the ones to be pushed to stack A in order for them to get to the lower side of stack A.


- Example of stack B after the first phase (A is obviously empty):
```bash

[ "100, 97, 92, 99, 91," 87, 93, 89, 88, 84, 80, 77, 76, 74, 79, 78, 66, 72, 69, 59, 63, 60, 49, 52, 58, 44, 47, 53, 43, 48, 50, 46, 37, 33, 32, 29, 30, 27, 31, 16, 22, 26, 23, 17, 7, 14, 6, 11, "8, 3, 4, 1, 2, 10, 5, 15, 0," 12, 13, 21, 20, 9, 25, 19, 18, 28, 24, 38, 41, 34, 35, 39, 36, 45, 42, 40, 55, 56, 54, 62, 57, 67, 65, 61, 71, 68, 64, 73, 70, 75, 85, 81, 83, 86, 82, "95, 94, 96, 90, 98" ]

```

we can clearly see that the smallest numbers are burried in the middle of the stack and the greater numbers are closer to the head (even the ones in that are the bottom of the stack are closer to the head than the ones in middle)
***
**PHASE 2:** Pushing the numbers back to A:

- This phase is more straigh forward and less confusing than the first: We find the node with the biggest number and push it back to A, that's it.

- The only thing we need to determinese is whether the biggest number is in the higher part of the stack or in the lower part, for we need this to know which operator we should perform, for example, if the biggest number in the stack is in the upper part of the stack, it will be easier to get to the top using the operation "rb", opposite to this, when the number is in the bottom of the stack, we use "rrb" that way we get the node to the top much faster.

- Stack A after the phase 2 is done (again B is of course empty):
```
[ 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100 ]
```
fascinating, right?

# Resources:

- As big as this project is, the resources of it online are not very generous, though, I still found some artcles that helped get the overview of this project:

https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
- This article was made by one of the previous 42 students, covering all the basics you need to know before diving to the project, and he also implemented and explained the chunks method in this article.

https://www.youtube.com/watch?v=wRvipSG4Mmk&t=1219s
- A youtube tutorial that explains the projects clearly, although, she implemented a different sorting algorithm called the **Turk Algorithm**, which is a bit hard coded and it is not elegant.
