# Lab 05 - Two-dimensional arrays

[Assignment](docs/lw-task-05.pdf) · [Report](docs/lw-report-05.pdf)

Variant 9. The goal of the lab is to learn to work with two-dimensional arrays:
to fill and print a matrix with nested loops, to process it row by row and
column by column, and to build new matrices from the given ones.

## Overview

| Task | Option 1 of the assignment                                                          |
|------|-------------------------------------------------------------------------------------|
| 1    | Matrix `6x3`: choose an element `A[i][j]` and delete the column it is in            |
| 2    | Matrix `7x9`: arithmetic mean of the elements and the number of smaller elements    |
| 3    | Matrices `7x9` and `9x4`: product `C = A x B`                                       |

### Project layout

```
lab_05/
├── include/
│   ├── tasks.h   # task registry (X-macro), TASK_COUNT, run_task() / run_all_tasks()
│   ├── utils.h   # validated input
│   └── matrix.h  # constants, matrix functions, Matrix type
└── src/
    ├── main.c    # menu, task number parsing, srand()
    ├── runner.c  # dispatches to run_task1() ... run_task3()
    ├── taskN.c   # each task 'N' in its own source file
    ├── ...
    ├── matrix.c  # implementation of matrix functions
    └── utils.c   # implementation of utility functions
```

## Program flow

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>task or Enter"/]
  B --> C{"Valid?"}
  C -->|No| D[/"Output<br/>error"/]
  D --> B
  C -->|"Enter"| E["run_task(i)<br/>(all tasks in order)"]
  C -->|"1..TASK_COUNT"| F["run_task(task)"]
  E --> M{"Next task<br/>exists?"}
  M -->|No| H(["Stop"])
  M -->|Yes| N{"Ask 'Proceed to<br/>next task? (Y/n)'"}
  N -->|"Yes (default)"| E
  N -->|No| H
  F --> H

  classDef stage stroke:#666,rx:6,ry:6
  class A,B,C,D,E,F,H,M,N stage
```

## Task 1 - Delete the column of a chosen element

Given a matrix `A` (variant 9: `6x3`), choose an element `A[i][j]` and delete
the column `j` in which it is located. The element is chosen by the user: `i`
and `j` are entered and checked against the size of the matrix.

The column is deleted in place: in every row all elements to the right of the
column `j` move one place to the left, and the number of columns decreases by
one. The matrix `6x3` becomes `6x2`. If the matrix had only one column, nothing
is left and the program says so.

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>rows, cols"/]
  B --> C{{"From i = 0 to rows - 1"}}
  C --> D{{"From j = 0 to cols - 1"}}
  D --> E[/"Input / random<br/>A[i][j]"/]
  E --> D
  D --> C
  C --> F[/"Input<br/>row, col (inside A)"/]
  F --> G{{"From i = 0 to rows - 1"}}
  G --> H{{"From j = col to cols - 2"}}
  H --> I["A[i][j] = A[i][j + 1]"]
  I --> H
  H --> G
  G --> J["cols = cols - 1"]
  J --> K{"cols == 0"}
  K -->|Yes| L[/"Output<br/>'the matrix is empty'"/]
  K -->|No| M[/"Output<br/>A"/]
  L --> N(["Stop"])
  M --> N

  classDef stage stroke:#666,rx:6,ry:6
  class A,B,C,D,E,F,G,H,I,J,K,L,M,N stage
```

## Task 2 - Mean of the elements and the smaller ones

Given a matrix `A` (variant 9: `7x9`), find the arithmetic mean of its elements
and the number of elements smaller than it. The first pair of nested loops
collects the sum, then `mean = sum / (rows * cols)` (as a real number), the
second pair counts the elements `A[i][j] < mean`.

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>rows, cols"/]
  B --> C{{"From i = 0 to rows - 1"}}
  C --> D{{"From j = 0 to cols - 1"}}
  D --> E[/"Input / random<br/>A[i][j]"/]
  E --> D
  D --> C
  C --> F["sum = 0"]
  F --> G{{"From i = 0 to rows - 1"}}
  G --> H{{"From j = 0 to cols - 1"}}
  H --> I["sum = sum + A[i][j]"]
  I --> H
  H --> G
  G --> J["mean = sum / (rows * cols)<br/>smaller = 0"]
  J --> K{{"From i = 0 to rows - 1"}}
  K --> L{{"From j = 0 to cols - 1"}}
  L --> M{"A[i][j] < mean"}
  M -->|Yes| N["smaller = smaller + 1"]
  M -->|No| L
  N --> L
  L --> K
  K --> O[/"Output<br/>mean, smaller"/]
  O --> P(["Stop"])

  classDef stage stroke:#666,rx:6,ry:6
  class A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P stage
```

## Task 3 - Product of matrices

Given a matrix `A` and a matrix `B`, find the product `C = A x B` and write it
into the matrix `C`. `C` has as many rows as `A` and as many columns as `B`, and
each element is the sum of products of a row of `A` and a column of `B`:

```
C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + ... + A[i][n-1] * B[n-1][j]
```

where `n` is the number of columns of `A` (and of rows of `B`). Three nested
loops are used: over the rows of `C`, over its columns, and over `k` inside the
sum.

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>rows of A, cols of A"/]
  B --> C{{"From i = 0 to rows of A - 1"}}
  C --> D{{"From j = 0 to cols of A - 1"}}
  D --> E[/"Input / random<br/>A[i][j]"/]
  E --> D
  D --> C
  C --> F["rows of B = cols of A"]
  F --> G[/"Input<br/>cols of B"/]
  G --> H{{"From i = 0 to rows of B - 1"}}
  H --> I{{"From j = 0 to cols of B - 1"}}
  I --> J[/"Input / random<br/>B[i][j]"/]
  J --> I
  I --> H
  H --> K{{"From i = 0 to rows of A - 1"}}
  K --> L{{"From j = 0 to cols of B - 1"}}
  L --> M["C[i][j] = 0"]
  M --> N{{"From k = 0 to cols of A - 1"}}
  N --> O["C[i][j] = C[i][j] + A[i][k] * B[k][j]"]
  O --> N
  N --> L
  L --> K
  K --> P[/"Output<br/>A, B, C"/]
  P --> Q(["Stop"])

  classDef stage stroke:#666,rx:6,ry:6
  class A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q stage
```

## Results

| Task | Input                                                                   | Output                                                                                 |
|------|-------------------------------------------------------------------------|----------------------------------------------------------------------------------------|
| 1    | `A` is `6x3` with `1 ... 18` by rows, element `A[2][1]`                 | column 1 is deleted, `A` is `6x2`: rows `1 3`, `4 6`, `7 9`, `10 12`, `13 15`, `16 18` |
| 1    | `A` is `1x1`, element `A[0][0]`                                         | `No columns are left, the matrix is empty.`                                            |
| 2    | `A` is `2x3`: `1 2 3` / `4 5 6`                                         | mean `3.5000`, `3` elements are smaller                                                |
| 3    | `A` is `2x3`: `1 2 3` / `4 5 6`, `B` is `3x2`: `7 8` / `9 10` / `11 12` | `C` is `2x2`: `58 64` / `139 154`                                                      |

## Build & run

Standalone (from this directory):

```bash
make build
make run
```

From the repository root:

```bash
make build LAB=05
make run LAB=05
```
