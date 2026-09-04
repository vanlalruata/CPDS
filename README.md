# C Programming & Data Structures — Practical Question Bank

A comprehensive, exam-oriented practical question bank with complete, compilable C programs.

## Course

**Practical resource for:**
- MCA
- M.Sc. (Mathematics)
- B.Tech. (CSE)
- B.Tech. (IT)
- M.Tech. (CSE)
- B.Tech. (ECE)
- M.Tech. (ECE)
- (and related programmes)

**Offered by:** Mizoram University

**Prepared by:** Dr. Vanlalruata Hnamte  
**Department of Mathematics and Computer Science**  
**Mizoram University**

## Syllabus Coverage

This question bank is organized to follow the two-unit syllabus.

### Unit I — 15 Hours
- Flow-chart concepts
- C programming
- Integer and real operations
- Control statements (`if-else`, `switch`, `break`, `continue`)
- Loops (`do-while`, `while`, `for`, nested loops)
- Functions
- Argument passing
- Arrays

### Unit II — 15 Hours
- Pointers
- Dynamic storage allocation
- Structures
- Introduction to Data Structures
- Complexity of algorithms
- Linear data structures: Linked List, Stack, Queue
- Nonlinear data structures: Trees

## How To Use

The programs are grouped into folders `part_a` through `part_v`. Inside each folder the
programs are named `q1.c`, `q2.c`, … in the same order as the questions listed below.

To compile a single program:

```bash
gcc part_b/q1.c -o part_b/q1
./part_b/q1
```

To compile and run every program in a folder (Linux/macOS):

```bash
for f in part_b/*.c; do gcc "$f" -o /tmp/a && ./tmp/a; done
```

## Folder / Question Index

| Folder | Topic | Questions |
|--------|-------|-----------|
| `part_a` | Flowchart and basic C programming | 24 |
| `part_b` | Integer and real operations | 25 |
| `part_c` | if, if-else, nested if | 25 |
| `part_d` | switch, break, continue | 25 |
| `part_e` | Loops | 30 |
| `part_f` | Functions | 30 |
| `part_g` | Argument passing | 25 |
| `part_h` | Arrays | 40 |
| `part_i` | Pointers | 40 |
| `part_j` | Dynamic memory allocation | 35 |
| `part_k` | Structures | 35 |
| `part_l` | Union | 20 |
| `part_m` | Algorithm complexity | 25 |
| `part_n` | Linked list (singly + circular) | 50 |
| `part_o` | Doubly linked list | 25 |
| `part_p` | Stack (array + linked list) | 45 |
| `part_q` | Queue | 20 |
| `part_r` | Circular queue | 20 |
| `part_s` | Trees | 30 |
| `part_t` | Integrated practical questions | 30 |
| `part_u` | Debugging / output-based | 30 |
| `part_v` | High-value practical exam questions + memory management | 25 |
| `part_w` | Algorithm complexity (advanced) + Trees (advanced) | 50 |
| **Total** | | **704** |

## Detailed Question Numbering

### `part_a` — Flowchart and Basic C Programming (q1–q24)
1. Largest of two numbers
2. Largest of three numbers
3. Positive, negative, or zero
4. Even or odd
5. Sum of first N natural numbers
6. Factorial of a number
7. Prime number check
8. Reverse an integer
9. Palindrome number check
10. Sum of digits
11. Count digits in an integer
12. Calculate x^n
13. Generate Fibonacci series
14. GCD of two numbers
15. LCM of two numbers
16. Roots of a quadratic equation
17. Electricity bill (slabs)
18. Grade from marks
19. Sum of even numbers between two limits
20. Sum of odd numbers between two limits
21. Largest and smallest among N numbers
22. Leap year check
23. Decimal to binary
24. Binary to decimal

### `part_b` — Integer and Real Operations (q1–q25)
1. Addition, subtraction, multiplication, division of two integers
2. Average of three numbers
3. Simple interest
4. Compound interest
5. Area and circumference of a circle
6. Area of triangle (base × height)
7. Area of triangle (Heron's formula)
8. Volume and surface area of a sphere
9. Celsius to Fahrenheit
10. Fahrenheit to Celsius
11. Kilometres → metres, centimetres, millimetres
12. Seconds → hours, minutes, seconds
13. Gross salary from basic + allowances
14. Net salary after deductions
15. Percentage and grade from five subjects
16. Swap using temporary variable
17. Swap without third variable
18. Roots of a quadratic equation
19. Distance between two points
20. Midpoint of two points
21. Total bill including GST
22. Discount and final price
23. EMI for a loan
24. Profit/loss and percentage
25. Evaluate mixed int/float expression

### `part_c` — if / if-else / nested if (q1–q25)
1. Positive, negative or zero
2. Even or odd
3. Largest of two numbers
4. Largest of three numbers
5. Smallest of three numbers
6. Voting eligibility by age
7. Pass or fail
8. Grade from percentage
9. Leap year
10. Uppercase letter check
11. Lowercase letter check
12. Digit check
13. Vowel or consonant
14. Valid triangle (three sides)
15. Equilateral / isosceles / scalene
16. Acute / right / obtuse triangle
17. Quadratic roots (all cases)
18. Electricity bill (slabs)
19. Income tax (slabs)
20. Employee bonus (salary + service)
21. Quadrant of a point
22. Middle of three numbers
23. Second-largest of three numbers
24. Valid date
25. Date in a leap year

### `part_d` — switch, break, continue (q1–q25)
1. Calculator using switch
2. Menu-driven arithmetic operations
3. Day name from 1–7
4. Month name from 1–12
5. Days in a given month
6. Menu-driven unit conversion
7. Menu-driven area calculator
8. Menu-driven temperature conversion
9. Menu-driven student result
10. Menu-driven banking
11. Menu-driven even/odd & positive/negative
12. Simple ATM menu
13. Factorial / prime / palindrome / Armstrong menu
14. Restaurant billing (switch)
15. Grading system (switch)
16. Repeat choice until Exit (break)
17. Loop terminates on 0 (break)
18. 1–100 skip multiples of 5 (continue)
19. 1–100 except even (continue)
20. Sum of positives; stop on negative (break)
21. Read until a prime is entered
22. Read until a palindrome is entered
23. Menu-driven matrix operations
24. Menu-driven string operations
25. Menu-driven array operations

### `part_e` — Loops (q1–q30)
1. Print 1 to N
2. Print N to 1
3. Even numbers 1 to N
4. Odd numbers 1 to N
5. Sum 1 to N
6. Sum of evens up to N
7. Sum of odds up to N
8. Factorial of N
9. Multiplication table of a number
10. Tables 1 to 10
11. Count digits
12. Sum of digits
13. Product of digits
14. Reverse a number
15. Palindrome check
16. Armstrong check
17. Perfect number check
18. Strong number check
19. Prime check
20. Primes between two limits
21. GCD
22. LCM
23. Fibonacci series
24. Nth Fibonacci
25. x^n without pow()
26. Pattern: right triangle (`*`, `**`, …)
27. Pattern: inverted right triangle
28. Pattern: 1 / 12 / 123 / 1234 / 12345
29. Pattern: 1 / 22 / 333 / 4444 / 55555
30. Pyramid pattern using `*`

### `part_f` — Functions (q1–q30)
1. Add two numbers
2. Subtract two numbers
3. Multiply two numbers
4. Divide two numbers
5. Square
6. Cube
7. Maximum of two
8. Maximum of three
9. Even/odd check
10. Prime check
11. Factorial
12. Power
13. Reverse number
14. Palindrome check
15. Sum of digits
16. GCD
17. LCM
18. Fibonacci series
19. Armstrong check
20. Perfect check
21. Swap
22. Largest in array
23. Sum of array
24. Search in array
25. Sort array
26. Reverse array
27. Average of array
28. Count even/odd in array
29. Menu-driven calculator (functions)
30. Student result (functions)

### `part_g` — Argument Passing (q1–q25)
1. Pass two ints to a function
2. No args, no return
3. Args, no return
4. No args, return value
5. Args + return value
6. Swap using ordinary args
7. Show parameter change does not affect caller
8. Factorial returning result
9. Maximum returning result
10. Return prime check
11. Multiple results via pointer params
12. Sum & average via pointer params
13. Quotient & remainder via pointer params
14. Swap using pointers
15. Min & max of array via pointers
16. Pass array, display
17. Pass array, sum
18. Pass array, search
19. Pass array, sort
20. Pass 2D array
21. Add two matrices
22. Multiply two matrices
23. Transpose a matrix
24. Pass structure to function
25. Pass pointer to structure

### `part_h` — Arrays (q1–q40)
1. Read & display array
2. Sum of elements
3. Average
4. Maximum
5. Minimum
6. Second-largest
7. Second-smallest
8. Count even/odd
9. Count positive/negative/zero
10. Linear search
11. Count occurrences
12. Find duplicates
13. Remove duplicates
14. Reverse array
15. Copy array
16. Merge two arrays
17. Common elements
18. Union
19. Difference
20. Rotate left by one
21. Rotate right by one
22. Rotate left by k
23. Rotate right by k
24. Insert at position
25. Delete at position
26. Bubble sort
27. Selection sort
28. Insertion sort
29. Sort ascending
30. Sort descending
31. Linear search
32. Binary search
33. Compare linear vs binary search
34. First occurrence
35. Last occurrence
36. Add two matrices
37. Subtract two matrices
38. Multiply two matrices
39. Transpose
40. Symmetric matrix check

### `part_i` — Pointers (q1–q40)
1. Declare int pointer, print address
2. Print value via pointer
3. Modify via pointer
4. `&` and `*` usage
5. Pointers to int/float/char/double
6. Size of pointer types
7. Pointer initialization
8. NULL pointer safety
9. Multiple pointers to one variable
10. Pointer to a pointer
11. Increment pointer
12. Decrement pointer
13. `p + n`
14. `p - n`
15. Difference of two pointers
16. Traverse array via pointer
17. Print array without indexing
18. Reverse array via pointers
19. Maximum via pointers
20. Minimum via pointers
21. Swap via pointers
22. Min & max via pointer params
23. Sum via pointer param
24. Multiple returns via pointers
25. Pass array via pointer
26. Sort via pointers
27. Reverse via pointers
28. Search via pointers
29. Pass 2D array via pointer
30. Pointer-to-pointer
31. malloc one int
32. malloc an array
33. Pointer to structure
34. `->` member access
35. Array of structure pointers
36. Pointer to function
37. Pointer arithmetic on struct array
38. Dynamic matrix (`int **`)
39. Dynamic array of strings (`char **`)
40. Dynamic student record

### `part_j` — Dynamic Memory Allocation (q1–q35)
1. malloc one int
2. malloc one float
3. malloc int array
4. malloc float array
5. malloc char array
6. Input/display dynamic array
7. Sum of dynamic array
8. Max of dynamic array
9. Min of dynamic array
10. Search dynamic array
11. Sort dynamic array
12. Reverse dynamic array
13. calloc int array
14. calloc zero-initialization demo
15. Compare malloc vs calloc
16. Sum of calloc array
17. Dynamic matrix via calloc
18. realloc increase size
19. realloc decrease size
20. Resizable int array
21. Add to growing array
22. Dynamic list via realloc
23. Proper free()
24. NULL after free()
25. Fix memory leak
26. Fix use-after-free
27. Fix double-free
28. Fix invalid access
29. Dynamic single structure
30. Dynamic array of structures
31. Input student records dynamically
32. Search student records dynamically
33. Sort dynamic student records
34. Topper from dynamic records
35. First linked-list node via malloc

### `part_k` — Structures (q1–q35)
1. struct student
2. struct employee
3. struct book
4. struct product
5. struct bank account
6. Input/display student
7. Input/display employee
8. Array of students
9. Highest marks student
10. Lowest marks student
11. Search student by roll
12. Search employee by ID
13. Sort students by marks
14. Sort students by name
15. Sort employees by salary
16. Pass struct to function
17. Return struct from function
18. Pass struct pointer
19. `->` access
20. Nested structures
21. Structure containing a structure
22. Dynamic array of structures
23. Structure containing an array
24. Structure containing a pointer
25. Student record system
26. Employee management system
27. Library book management
28. Bank account management
29. Product inventory system
30. Total/average marks
31. Highest/lowest salary
32. Compare two structs
33. Copy one struct into another
34. Structure padding (sizeof)
35. Linked-list node structure

### `part_l` — Union (q1–q20)
1. Define & initialize a union
2. Store int in union
3. Store float in union
4. Store char in union
5. Union members share memory
6. sizeof(struct) vs sizeof(union)
7. Union of int/float/char
8. Cross-member interpretation demo + caution
9. Student union
10. Employee union
11. Compare struct vs union (same members)
12. Addresses of union members
13. Addresses of struct members
14. Memory-saving of unions
15. Union in menu-driven program
16. Array of unions
17. Struct containing a union
18. Union containing a struct
19. Practical union use case (tagged variant)
20. Compare memory: struct vs union design

### `part_m` — Algorithm Complexity (q1–q25)
Each file documents algorithm, TIME COMPLEXITY, and AUXILIARY SPACE.
1. Linear search
2. Binary search
3. Maximum in array
4. Minimum in array
5. Sum of array
6. Count occurrences
7. Bubble sort
8. Selection sort
9. Insertion sort
10. Reverse array
11. Duplicate elements (nested loops)
12. Matrix addition
13. Matrix multiplication
14. Matrix transpose
15. Factorial (iteration)
16. Factorial (recursion)
17. Fibonacci (iteration)
18. Fibonacci (recursion)
19. GCD (Euclidean)
20. Element in sorted array
21. Compare linear vs binary search
22. Compare bubble/selection/insertion sort
23. Analyze single loop
24. Analyze nested loops
25. Analyze three nested loops

### `part_n` — Linked List (q1–q50)
**Singly Linked List (q1–q30):**
1. Create list
2. Display list
3. Count nodes
4. Sum of nodes
5. Maximum node
6. Minimum node
7. Search
8. Insert at beginning
9. Insert at end
10. Insert at position
11. Insert after value
12. Insert before value
13. Delete first
14. Delete last
15. Delete at position
16. Delete by value
17. Reverse list
18. Middle node
19. Nth node from end
20. Count occurrences
21. Find duplicates
22. Remove duplicates
23. Sort list
24. Merge two sorted lists
25. Concatenate two lists
26. Compare two lists
27. Copy a list
28. Palindrome check
29. Detect cycle
30. Remove cycle

**Circular Linked List (q31–q50):**
31. Create circular list
32. Display circular list
33. Insert at beginning
34. Insert at end
35. Insert at position
36. Delete from beginning
37. Delete from end
38. Delete specified node
39. Search
40. Count nodes
41. Reverse circular list
42. Josephus problem
43. Split into two halves
44. Concatenate two circular lists
45. Sort circular list
46. Maximum element
47. Minimum element
48. Check whether list is circular
49. Convert singly → circular
50. Circular queue using linked list

### `part_o` — Doubly Linked List (q1–q25)
1. Create list
2. Display forward
3. Display backward
4. Insert at beginning
5. Insert at end
6. Insert at position
7. Insert before node
8. Insert after node
9. Delete first
10. Delete last
11. Delete specified node
12. Search
13. Count nodes
14. Maximum
15. Minimum
16. Reverse list
17. Sort list
18. Remove duplicates
19. Merge two lists
20. Compare two lists
21. Middle node
22. Nth from end
23. Deque using DLL
24. Browser forward/back
25. Undo/redo

### `part_p` — Stack (q1–q45)
**Array Stack (q1–q25):**
1. Stack using array
2. push()
3. pop()
4. peek()
5. isEmpty()
6. isFull()
7. Display
8. Overflow handling
9. Underflow handling
10. Menu-driven stack
11. Reverse string
12. Reverse array
13. Balanced parentheses
14. Balanced brackets
15. Infix → postfix
16. Evaluate postfix
17. Infix → prefix
18. Evaluate prefix
19. Palindrome via stack
20. Two stacks in one array
21. Multiple stacks concept
22. Sort a stack
23. Reverse a stack
24. Minimum in stack
25. Dynamic-memory stack

**Linked-list Stack (q26–q45):**
26. Stack using linked list
27. Push at beginning
28. Pop from beginning
29. Peek
30. Display
31. Check empty
32. Reverse stack
33. Sort stack
34. Postfix via LL stack
35. Balanced parentheses (LL)
36. Infix → postfix (LL)
37. Undo operation
38. Browser history
39. Explicit-stack recursion
40. Compare array vs LL stack
41. Two stacks using LL
42. Overflow concept (dynamic)
43. Stack of structures
44. Student-record stack
45. Dynamic-node stack

### `part_q` — Simple Queue (q1–q20)
1. Queue using array
2. enqueue()
3. dequeue()
4. front()
5. rear()
6. isEmpty()
7. isFull()
8. Display
9. Overflow
10. Underflow
11. Menu-driven queue
12. Queue using linked list
13. Insert (LL)
14. Delete (LL)
15. Dynamic-node queue
16. Queue of integers
17. Queue of structures
18. Customer service simulation
19. Printer scheduling
20. CPU process scheduling

### `part_r` — Circular Queue (q1–q20)
1. Circular queue (array)
2. enqueue()
3. dequeue()
4. front()
5. rear()
6. isEmpty()
7. isFull()
8. Display
9. Wrap-around
10. Why better than simple queue
11. Menu-driven circular queue
12. Circular queue (linked list)
13. Circular queue of structures
14. CPU scheduling
15. Round-robin scheduling
16. Circular buffer
17. Josephus problem
18. Producer-consumer buffering
19. Compare simple vs circular queue
20. Time-complexity analysis

### `part_s` — Trees (q1–q30)
**Binary Tree (q1–q20):**
1. Create binary tree
2. Linked-node representation
3. Preorder
4. Inorder
5. Postorder
6. Level-order
7. Count nodes
8. Count leaf nodes
9. Count internal nodes
10. Height
11. Depth of a node
12. Maximum element
13. Minimum element
14. Search
15. Nodes with one child
16. Nodes with two children
17. Sum of nodes
18. Nodes at a level
19. Mirror image
20. Identical trees

**Binary Search Tree (q21–q30):**
21. Create BST
22. Insert
23. Search
24. Delete
25. Minimum
26. Maximum
27. Inorder predecessor
28. Inorder successor
29. Height of BST
30. Display (all DFS) + BST validity check

### `part_t` — Integrated Practical Questions (q1–q30)
1. Student Management System
2. Dynamic Student Management System
3. Employee Management System
4. Library Management System
5. Bank Account System
6. Contact Management System
7. Dynamic Array Program
8. Stack-Based Expression Evaluator
9. Parentheses Checker
10. Browser History
11. Polynomial Representation
12. Sparse Matrix
13. Student Queue
14. Printer Queue
15. CPU Scheduling (round-robin)
16. Undo System
17. Dynamic Linked List
18. Sorted Linked List
19. Polynomial Addition
20. Polynomial Multiplication
21. Stack Using Linked List
22. Queue Using Linked List
23. BST Student Records
24. BST Dictionary
25. Tree Traversal Comparison
26. Dynamic Matrix
27. Dynamic Student Records + Sorting
28. Menu-Driven Data Structure Program
29. Linked List-Based Polynomial Calculator
30. Complete Student Record Data Structure

### `part_u` — Debugging / Output-Based (q1–q30)
Each file shows the original BUGGY code (commented), the corrected program, and an explanation of the error and fix.
1. Off-by-one array loop
2. Incorrect scanf()
3. Uninitialized variable
4. Infinite loop
5. switch fall-through
6. Incorrect break
7. Incorrect continue
8. Prototype mismatch
9. Incorrect return type
10. Missing return
11. Incorrect argument passing
12. Incorrect pointer declaration
13. Incorrect dereferencing
14. NULL pointer dereference
15. Dangling pointer
16. Memory leak
17. Double free
18. Incorrect malloc size
19. Incorrect calloc usage
20. Unsafe realloc usage
21. Array out-of-bounds
22. Incorrect struct member access
23. `.` vs `->`
24. Incorrect linked-list insertion
25. Incorrect linked-list deletion
26. Stack overflow handling
27. Stack underflow handling
28. Queue overflow/underflow handling
29. Incorrect tree traversal
30. Output of pointers+arrays program

### `part_v` — High-Value Practical Exam Questions + Memory Management (q1–q25)
1. Factorial using function
2. Prime using function
3. Array maximum/minimum
4. Linear search
5. Bubble sort
6. Matrix addition
7. Pointer-based swap
8. Structure-based student record
9. Dynamic array using malloc()
10. Stack using array
11. malloc single integer (read/print/free)
12. malloc array of integers (sum/average/free)
13. malloc array of floats (average/free)
14. calloc array of integers (zero-initialization demo)
15. malloc vs calloc experimental comparison
16. realloc to grow an array (preserve old data)
17. realloc to shrink an array
18. Dynamic 2D matrix (int **) using malloc
19. Dynamic 2D matrix using calloc (input/display/transpose)
20. free() and setting pointer to NULL afterwards
21. Identify and correct a memory leak
22. Identify and correct use-after-free
23. Identify and correct double-free
24. Dynamic array of strings (char **) with free
25. Dynamic integer list grown with realloc in a loop

### `part_w` — Algorithm Complexity (Advanced) + Trees (Advanced) (q1–q50)
**Algorithm Complexity (q1–q22):**
1. Big-O definition + demonstration on f(n)=3n+2
2. Big-Ω (Omega) lower bound + demonstration
3. Big-Θ (Theta) tight bound + demonstration
4. Linear search: best/avg/worst comparison counts
5. Binary search: best/avg/worst comparison counts
6. Bubble sort: best/avg/worst comparisons and swaps
7. Insertion sort: best/avg/worst comparisons
8. Quick sort (Lomuto): best/avg/worst comparisons
9. Analyze a single loop (sum 1..N) — O(n) time, O(1) space
10. Analyze two nested loops — O(n^2)
11. Analyze three nested loops (naive matrix multiply) — O(n^3)
12. Analyze a logarithmic loop (n/=2) — O(log n)
13. Analyze a linear while loop
14. Recursive factorial with step counter — T(n)=T(n-1)+c
15. Recursive Fibonacci with call counter — O(2^n)
16. Binary search recurrence T(n)=T(n/2)+c
17. Time vs auxiliary space: bubble sort (O(1) extra)
18. Time vs auxiliary space: merge sort (O(n) extra)
19. Growth rates table: log n, n, n log n, n^2, 2^n
20. Operation counter on linear search (best/avg/worst)
21. Amortized analysis: dynamic array doubling
22. Identify complexity class of given snippets

**Tree Terminology & Binary Trees (q23–q37):**
23. Tree terminology on a built tree (root/leaves/internal/edges/depth/height/subtrees)
24. Binary tree representation using linked nodes
25. Build a binary tree interactively
26. Preorder traversal
27. Inorder traversal
28. Postorder traversal
29. Level-order traversal (using a queue)
30. Count total nodes
31. Count leaf nodes
32. Count internal nodes
33. Height of a binary tree
34. Depth of a given node
35. Maximum and minimum element
36. Search for an element
37. Mirror image of a binary tree

**Binary Search Trees (q38–q47):**
38. BST insert
39. BST search
40. BST delete (0/1/2 children + inorder successor)
41. Minimum in BST
42. Maximum in BST
43. Inorder predecessor
44. Inorder successor
45. kth smallest element
46. kth largest element
47. Height of BST + relation between height and performance

**Applications & Comparison (q48–q50):**
48. Applications of trees: expression tree evaluation
49. Comparison table: Array vs Linked List vs Stack vs Queue vs Tree
50. Menu-driven data-structure advisor

## Notes for Students

- For **Part A** the task asks you to *draw* the flowchart first; each file contains a
  short ASCII flowchart plus the corresponding C program so you can verify your logic.
- All programs are written in standard C (C99/C11) and compile with `gcc`.
- Where a question asks for complexity analysis (Part M), the time and auxiliary-space
  complexity is given in comments at the top of the file.
- Memory allocated with `malloc`/`calloc`/`realloc` is released with `free` in every
  program that uses dynamic allocation.

---

*Prepared by Dr. Vanlalruata Hnamte, Department of Mathematics and Computer Science,
Mizoram University.*
