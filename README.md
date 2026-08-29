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
| `part_v` | High-value practical exam questions | 10 |

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
