# Lab 07 - Strings

[Assignment](docs/lw-task-07.pdf) · [Report](docs/lw-report-07.pdf)

Variant 9. The goal of the lab is to study the basic algorithms for working with
strings: a string as an array of `char` ending with `'\0'`, reading a line,
going through it character by character, splitting it into words with `strtok()`
and using the functions of `<string.h>`.

## Overview

| Task | Option 1 of the assignment                                                           |
|------|--------------------------------------------------------------------------------------|
| 1    | Replace the symbols `+`, `-`, `*` of the line with spaces                            |
| 2    | Split a text into words separated by `:`, `;`, `-` and a space; print and count them |
| 3    | Find the shortest and the longest word of the line, print them and their lengths     |

### Project layout

```
lab_07/
├── include/
│   ├── tasks.h   # task registry (X-macro), TASK_COUNT, run_task() / run_all_tasks()
│   └── utils.h   # MAX_LINE_SIZE, validated input, read_text_line(), text_length()
└── src/
    ├── main.c    # menu, task number parsing, setlocale()
    ├── runner.c  # dispatches to run_task1() ... run_task3()
    ├── taskN.c   # each task 'N' in its own source file
    ├── ...
    └── utils.c   # implementation of utility functions
```

## Program flow

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Output<br/>title of the lab"/]
  B --> C["{init}"]
  C --> D[/"Input<br/>task or Enter"/]
  D --> E{"Valid?"}
  E -->|No| F[/"Output<br/>error"/]
  F --> D
  E -->|"1..TASK_COUNT"| G[["run_task(task)"]]
  E -->|"Enter"| H{{"From i = 1 to TASK_COUNT"}}
  H --> I[["run_task(i)"]]
  I --> J{"i < TASK_COUNT"}
  J -->|Yes| K[/"Input<br/>'Proceed to task i + 1? (Y/n)'"/]
  J -->|No| H
  K --> L{"Answer is yes<br/>(Enter = yes)"}
  L -->|Yes| H
  L -->|No| M
  H --> M[/"Output<br/>'Press Enter to exit'"/]
  G --> M
  M --> N[/"Input<br/>Enter"/]
  N --> O(["Stop"])

  classDef stage stroke:#666,rx:6,ry:6
  class A,B,C,D,E,F,H,M,N stage
```

## Task 1 - Replace the symbols with spaces

The line is read and then gone through character by character with a pointer
`p`. If the character is one of `+`, `-`, `*` (it is searched in the string
`"+-*"` with `strchr()`), it is replaced with a space and counted. The loop
stops at the terminating `'\0'`; the check `*p != '\0'` is needed because
`strchr()` also "finds" the terminating character of the string it searches in.

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>line"/]
  B --> C["count = 0"]
  C --> D{{"From p = line to '\0'"}}
  D --> E{"*p is '+', '-' or '*'"}
  E -->|Yes| F["*p = ' '<br/>count = count + 1"]
  E -->|No| D
  F --> D
  D --> G[/"Output<br/>line, count"/]
  G --> H(["Stop"])

  classDef stage stroke:#666,rx:6,ry:6
  class A,B,C,D,E,F,G,H stage
```

## Task 2 - Words separated by a colon, a semicolon, a hyphen and a space

The text is split with `strtok()`, the separators are given by the string
`":;- "`. The first call gets the string, the next ones get `NULL` and continue
from the place where the previous call stopped; `NULL` is returned when there
are no more words. `strtok()` writes `'\0'` into the string it splits, so the
work is done on a copy and the entered text stays intact. Several separators in
a row do not produce empty words.

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>text"/]
  B --> C["work = copy of text<br/>count = 0"]
  C --> D["word = strtok(work, ':;- ')"]
  D --> E{"word != NULL"}
  E -->|Yes| F["count = count + 1"]
  F --> G[/"Output<br/>count, word"/]
  G --> H["word = strtok(NULL, ':;- ')"]
  H --> E
  E -->|No| I{"count == 0"}
  I -->|Yes| J[/"Output<br/>'(none)'"/]
  I -->|No| K[/"Output<br/>count"/]
  J --> K
  K --> L(["Stop"])

  classDef stage stroke:#666,rx:6,ry:6
  class A,B,C,D,E,F,G,H,I stage
```

## Task 3 - The shortest and the longest word

The line is scanned once. For every word the function `next_word()` skips the
characters that are not parts of a word, finds the end of the word, and returns
its start, its size in bytes and its length in characters. The words are not
copied: the program keeps only a pointer to the beginning and the size, and the
word is printed with `%.*s`. The length is the smaller of the two for `shortest`
and the larger for `longest`, compared strictly, so the first word wins in case
of a tie. If there are no words, the program says so.

```mermaid
flowchart TD
  A(["Start"]) --> B[/"Input<br/>text"/]
  B --> C["p = text<br/>count = 0"]
  C --> D{"*p != '\\0' and<br/>*p is not a word character"}
  D -->|Yes| D1["p = p + 1"]
  D1 --> D
  D -->|No| E["start = p"]
  E --> F{"*p != '\\0' and<br/>*p is a word character"}
  F -->|Yes| F1["p = p + 1"]
  F1 --> F
  F -->|No| G{"p == start"}
  G -->|Yes| K{"count == 0"}
  K -->|Yes| L[/"Output<br/>'There are no words'"/]
  K -->|No| M[/"Output<br/>shortest, longest, count"/]
  L --> N(["Stop"])
  M --> N
  G -->|No| H["word = (start, p - start)"]
  H --> I{"count == 0 or<br/>word.length < shortest.length"}
  I -->|Yes| I1["shortest = word"]
  I -->|No| J{"count == 0 or<br/>word.length > longest.length"}
  I1 --> J
  J -->|Yes| J1["longest = word"]
  J -->|No| P["count = count + 1"]
  J1 --> P
  P --> D

  classDef stage stroke:#666,rx:6,ry:6
  class A,B,C,D,E,F,F1,G,G1,H,K,L,M,N stage
```

## Results

| Task | Input                              | Output                                                                   |
|------|------------------------------------|--------------------------------------------------------------------------|
| 1    | `2+3-4*5 a+b`                      | `2 3 4 5 a b`, replaced symbols: `5`                                     |
| 1    | `hello world`                      | `hello world`, replaced symbols: `0`                                     |
| 2    | `one:two;three-four five`          | words `one`, `two`, `three`, `four`, `five`; number of words: `5`        |
| 2    | `:;- `                             | `(none)`, number of words: `0`                                           |
| 3    | `I love programming in C language` | shortest `I` (1), longest `programming` (11), words: `6`                 |
| 3    | `ab, cd! ef; gh.`                  | shortest `ab` (2), longest `ab` (2): the first of equal ones, words: `4` |
| 3    | `я люблю програмування в Харкові`  | shortest `я` (1), longest `програмування` (13), words: `5`               |

## Build & run

Standalone (from this directory):

```bash
make build
make run
```

From the repository root:

```bash
make build LAB=07
make run LAB=07
```
