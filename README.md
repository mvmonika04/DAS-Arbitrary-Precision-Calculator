# Arbitrary Precision Calculator (APC)

## Overview
The Arbitrary Precision Calculator (APC) is a C programming project that performs arithmetic operations on large integers beyond the range of standard C data types. It uses a doubly linked list to represent numbers and perform calculations digit by digit.

## Problem Statement
Built-in C data types have limited storage capacity. When a number exceeds the supported range, integer overflow may occur and produce incorrect results. This project overcomes this limitation by representing large integers using a doubly linked list.

## Technologies Used
- Programming Language: C
- Data Structure: Doubly Linked List
- Concepts: Pointers, Dynamic Memory Allocation, String Handling, Input Validation
- Platform: Linux
- Compiler: GCC
- Build Tool: Makefile

## Features
- Addition of large integers
- Subtraction of large integers
- Multiplication of large integers
- Division of large integers
- Input validation
- Conversion of numeric strings into digit-based representation
- Dynamic memory allocation for linked-list nodes

## Working Procedure
1. Read two large integer inputs as strings.
2. Validate the input values.
3. Convert the strings into a doubly linked list representation.
4. Perform the selected arithmetic operation.
5. Display the calculated result.

## Sample Input and Output

### Addition
**Input**
```text
First number: 12345678901234567890
Second number: 98765432109876543210
Operation: +
```

**Output**
```text
Result: 111111111011111111100
```

### Subtraction
**Input**
```text
First number: 10000000000000000000
Second number: 123456789
Operation: -
```

**Output**
```text
Result: 9999999999876543211
```

### Multiplication
**Input**
```text
First number: 123456789
Second number: 987654321
Operation: *
```

**Output**
```text
Result: 121932631112635269
```

### Division
**Input**
```text
First number: 10000000000000000000
Second number: 4
Operation: /
```

**Output**
```text
Result: 2500000000000000000
```

## Learning Outcomes
- Understanding doubly linked lists and pointers
- Implementing arithmetic algorithms
- Practicing dynamic memory allocation
- Improving input validation and string handling
- Developing debugging and problem-solving skills in C

## Author
**Monika M V**

GitHub: [mvmonika04](https://github.com/mvmonika04)
