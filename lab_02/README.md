# Lab 02 - Branched algorithms

Assignment: [docs/task.pdf](docs/task.pdf)

Variant 9. The goal of the lab is to get familiar with the `if` / `else`
conditional operator, including nested conditionals, and to describe each
algorithm with a block diagram before writing the code.

## Overview

| Task | What it does                                                                |
|------|-----------------------------------------------------------------------------|
| 1    | Which quadrant (or axis, or the origin) a point `(x, y)` belongs to         |
| 2    | Classifies a person's age into preschooler / schoolboy / worker / pensioner |
| 3    | Evaluates a piecewise function of `x` (Table 2.1, variant 4)                |
| 4    | Sum of the first three digits of a four-digit integer `N`                   |

### Project layout

```
lab_02/
├── include/
│   ├── tasks.h   # task registry (X-macro), TASK_COUNT, run_task() / run_all_tasks()
│   └── utils.h   # read_double() / read_doubles(), PI
└── src/
    ├── main.c    # menu, task number parsing
    ├── runner.c  # dispatches to run_task1() ... run_task4()
    ├── taskN.c   # each task 'N' in its own source file
    ├── ...
    └── utils.c   # implementation of utility functions
```

## Program flow

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Print banner<br/>and task prompt"/]
  B --> C[/"Read a line"/]
  C --> D{"Empty line<br/>or end of input?"}
  D -->|Yes| E["run_all_tasks()<br/>(all tasks in order)"]
  D -->|No| F{"Whole line is a number<br/>in range 1-4?"}
  F -->|Yes| G["run_task(n)<br/>(selected task)"]
  F -->|No| H[/"Print error<br/>status = 1"/]
  E --> I[/"Print 'Press Enter to exit'"/]
  G --> I
  H --> I
  I --> J(["Stop"])

  classDef stage fill:#363636,stroke:#666,color:#fff,rx:6,ry:6
  class A,B,C,D,E,F,G,H,I,J stage
```

## Task 1 - Quadrant of a point

Given real numbers `x` and `y`, print which quadrant the point `(x, y)`
belongs to. Points on an axis (`x = 0` or `y = 0`) are not in any quadrant,
including the origin, and are reported separately.

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>x, y"/]
  B --> C{"Input valid?"}
  C -->|No| D[/"Print 'Invalid input.'"/]
  C -->|Yes| E{"x = 0 and y = 0?"}
  E -->|Yes| F[/"Print: origin"/]
  E -->|No| G{"x = 0?"}
  G -->|Yes| H[/"Print: on Y axis"/]
  G -->|No| I{"y = 0?"}
  I -->|Yes| J[/"Print: on X axis"/]
  I -->|No| K{"x > 0 and y > 0?"}
  K -->|Yes| L[/"Print: quadrant I"/]
  K -->|No| M{"x < 0 and y > 0?"}
  M -->|Yes| N[/"Print: quadrant II"/]
  M -->|No| O{"x < 0 and y < 0?"}
  O -->|Yes| P[/"Print: quadrant III"/]
  O -->|No| Q[/"Print: quadrant IV"/]
  D --> R(["Stop"])
  F --> R
  H --> R
  J --> R
  L --> R
  N --> R
  P --> R
  Q --> R

  classDef stage fill:#363636,stroke:#666,color:#fff,rx:6,ry:6
  class A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R stage
```

## Task 2 - Age group classification

Given a person's age in years, assign them to one of four groups. The
assignment names the groups (preschooler, schoolboy, worker, pensioner) but
does not give numeric boundaries, so the following were chosen and are only
enforced in this implementation, not dictated by the assignment:

| Group        | Age (years) |
|--------------|-------------|
| Preschooler  | 0-6         |
| Schoolboy    | 7-17        |
| Worker       | 18-59       |
| Pensioner    | 60 and up   |

Ages outside `0..130` are rejected as input errors rather than classified.

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>age"/]
  B --> C{"Input valid?"}
  C -->|No| D[/"Print 'Invalid input.'"/]
  C -->|Yes| E{"0 <= age <= 130?"}
  E -->|No| F[/"Print range error"/]
  E -->|Yes| G{"age <= 6?"}
  G -->|Yes| H[/"Print: preschooler"/]
  G -->|No| I{"age <= 17?"}
  I -->|Yes| J[/"Print: schoolboy"/]
  I -->|No| K{"age <= 59?"}
  K -->|Yes| L[/"Print: worker"/]
  K -->|No| M[/"Print: pensioner"/]
  D --> N(["Stop"])
  F --> N
  H --> N
  J --> N
  L --> N
  M --> N

  classDef stage fill:#363636,stroke:#666,color:#fff,rx:6,ry:6
  class A,B,C,D,E,F,G,H,I,J,K,L,M,N stage
```

## Task 3 - Piecewise function (Table 2.1, variant 4)

```
y = -5x + 2       for x < 0
y = x^3 / 0.5     for x >= 0
```

The two branches meet at `x = 0` with a jump (`y = 2` approaching from the left,
`y = 0` at and after `x = 0`); the assignment's graph shows the same
discontinuity.

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>x"/]
  B --> C{"Input valid?"}
  C -->|No| D[/"Print 'Invalid input.'"/]
  C -->|Yes| E{"x < 0?"}
  E -->|Yes| F["y = -5x + 2"]
  E -->|No| G["y = x^3 / 0.5"]
  F --> H[/"Output<br/>branch used, y"/]
  G --> H
  D --> I(["Stop"])
  H --> I

  classDef stage fill:#363636,stroke:#666,color:#fff,rx:6,ry:6
  class A,B,C,D,E,F,G,H,I stage
```

## Task 4 - Sum of the first three digits

Given a positive four-digit integer `N`, find the sum of its first three
digits (thousands, hundreds and tens place - i.e. all digits except the
last one).

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>N"/]
  B --> C{"Input valid?"}
  C -->|No| D[/"Print 'Invalid input.'"/]
  C -->|Yes| E{"1000 <= N <= 9999?"}
  E -->|No| F[/"Print range error"/]
  E -->|Yes| G["thousands = N / 1000<br/>hundreds = (N / 100) mod 10<br/>tens = (N / 10) mod 10"]
  G --> H["sum = thousands + hundreds + tens"]
  H --> I[/"Output<br/>digits, sum"/]
  D --> J(["Stop"])
  F --> J
  I --> J

  classDef stage fill:#363636,stroke:#666,color:#fff,rx:6,ry:6
  class A,B,C,D,E,F,G,H,I,J stage
```

## Results

| Task | Input            | Output                                      |
|------|------------------|---------------------------------------------|
| 1    | `x = 3`, `y = 4` | Quadrant I                                  |
| 2    | `age = 30`       | Worker                                      |
| 3    | `x = 2`          | `y = x^3 / 0.5 = 16.0000`                   |
| 4    | `N = 7346`       | digits `7 3 4 6`, sum of first three = `14` |

## Build & run

Standalone (from this directory):

```bash
make build
make run
```

From the repository root:

```bash
make build LAB=02
make run LAB=02
```
