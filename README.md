# Push_swap
Push_swap is a project that challenges you to implement a sorting algorithm for a stack of integers using a specific set of operations. The goal is to efficiently sort the integers in ascending order with the fewest possible moves. 

## Here's an overview of the project:
### Components:
#### 1.Stack a (Initial Configuration):
```
	.At the beginning, you have a stack (referred to as stack a) containing all the integers 
	that need to be sorted. 
	The integers are initially placed next to each other in a specific order.
```

#### 2.Operations:
```
	.Push (pa, pb): Moves the top element from one stack to the other.
	.Swap (sa, sb, ss): Swaps the top two elements on a stack or between two stacks.
	.Rotate (ra, rb, rr): Shifts all elements on a stack up by one position. The top element becomes the bottom one.
	.Reverse Rotate (rra, rrb, rrr): Shifts all elements on a stack down by one position. The bottom element becomes the top one.
```
## Objective:
```
	The main objective is to sort the numbers in stack a using a combination of these operations.
	The challenge is to design an algorithm that minimizes the total number of moves required to achieve the sorted order.
```

## Constraints:
```
   You must implement an algorithm that sorts the numbers.
   The number of moves should be minimized.
   The operations must be performed based on the rules defined.
```

## Optimization:
```
 	Optimizing the algorithm is a crucial aspect of the project. 
	You need to find an efficient sorting strategy that minimizes the number of moves. 
	This may involve identifying specific patterns, utilizing different sorting techniques, 
	and considering the overall efficiency of the algorithm.
```

# Learning Objectives:
```
	1.Gain a deeper understanding of sorting algorithms.
	2.Implement and optimize algorithms for specific constraints.
	3.Learn to work with data structures, especially stacks.
	4.Practice algorithmic problem-solving and optimization techniques.
```
## RESUME 
	The project aims to enhance your problem-solving skills, algorithmic thinking,
	and ability to optimize code for specific constraints.

# RUN PROGRAM:

For MANDATRY :
``` $ make ```
exmple usage :
```./push_swap 47 6 3 7 45 50 0 1```

For Bonus :
``` $make bonus ```
exmple usage :
```./checker 47 6 3 7 45 50 0 1```


# Breaker

**Random Integer Array Generator and Checker**

`breaker` is a versatile C program that generates a random array of integers, performs various operations, and optionally checks the results using a provided sorting algorithm. The tool is designed to be easy to use and provides flexibility in testing sorting algorithms.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
  - [Quick Start](#quick-start)
  - [Modes](#modes)
  - [Examples](#examples)
- [Additional Information](#additional-information)
- [Contributing](#contributing)
- [License](#license)

## Features

- Generates a random array of integers.
- Supports multiple modes to customize functionality.
- Optional integration with custom sorting algorithms.
- Displays the number of moves performed by a sorting algorithm.
- Validates input parameters for ease of use.
- Supports checking results using custom checkers.

## Usage

### Quick Start

To quickly generate a random array and display the number of moves performed by a sorting algorithm, use the following command:

```bash
./breaker NUMBER_OF_RANDOM_NUMBER [MODE]
```

### Modes

- `0`: Display the number of moves (default if not provided).
- `1`: Redirect moves to a custom checker (must be named `checker`).
- `2`: Redirect moves to a custom checker_Mac (must be named `checker_Mac`).

### Examples

1. **Display the Number of Moves:**

    ```bash
    ./breaker 100
    ```

2. **Redirect Moves to a Custom Checker:**

    ```bash
    ./breaker 100 1
    ```

3. **Redirect Moves to a Custom Checker_Mac:**

    ```bash
    ./breaker 100 2
    ```

### Additional Information

- Run `./breaker help` for more detailed information and usage examples.

## Resources

-[42-cursus] : https://42-cursus.gitbook.io/guide/rank-02/push_swap

-[linked-list] : https://youtube.com/playlist?list=PL-xf44VEEzDvoSUfauaGT-pfJu4j9aNjd&si=P2ayyQVx54lrNdii

##### BY zelabbas