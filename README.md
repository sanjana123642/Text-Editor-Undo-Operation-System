# Text Editor Undo Operation System

A console-based Undo system for a text editor, written in C. It stores editing actions on an **array-based stack** and reverses the most recent action first using **Pop** (LIFO).

Case Study 8 · Data Structures and Algorithms-1 · B.Tech CSE 2025-29, Semester II

## Problem Statement

A student edits a document by writing, deleting, inserting and modifying text. If an important paragraph is deleted by mistake, the editor must be able to reverse the latest operation. Repeated Undo must step back through the history one action at a time, and Undo with no earlier action must be handled safely.

## Features

- Stack (array implementation) that stores editing actions
- Five editing actions: Write, Delete, Insert, Modify, Paste
- Push on every new action
- Display of the full editing history, newest first
- Undo using Pop
- Peek to show the latest remaining action after each Undo
- Multiple Undo operations in a row
- Underflow handling: prints "Nothing to undo" when the stack is empty
- Overflow handling: prints a message when the history is full

## DSA Concepts Used

| Concept | Where it is used |
| --- | --- |
| Stack | Holds the editing history |
| LIFO | Newest action is undone first |
| Push | Records a new action |
| Pop | Undo |
| Peek | Shows the latest remaining action |
| Array implementation | `char stack[MAX][LEN]` with a `top` index |

## Project Structure

```
.
├── undo.c      # source code
└── README.md   # this file
```

Save the program from the project report as `undo.c`.

## How to Compile and Run

Requires a C compiler such as GCC.

```bash
gcc undo.c -o undo
./undo
```

On Windows (MinGW):

```bash
gcc undo.c -o undo.exe
undo.exe
```

## Menu

```
1.Write 2.Delete 3.Insert 4.Modify 5.Paste
6.Undo 7.Show history 8.Peek 0.Exit
```

## Sample Run

```
Choice: 1
Enter text/details: Introduction to Stacks
Action recorded: Write: Introduction to Stacks

Choice: 2
Enter text/details: paragraph 2
Action recorded: Delete: paragraph 2

Choice: 7
Editing history (newest first):
  2. Delete: paragraph 2
  1. Write: Introduction to Stacks

Choice: 6
Undone: Delete: paragraph 2
Latest action: Write: Introduction to Stacks

Choice: 6
Undone: Write: Introduction to Stacks
No actions remaining.

Choice: 6
Nothing to undo.
```

## Complexity

| Operation | Time | Space |
| --- | --- | --- |
| Push | O(1) | O(1) |
| Pop (Undo) | O(1) | O(1) |
| Peek | O(1) | O(1) |
| Display | O(n) | O(1) |

The fixed array uses O(MAX × LEN) memory (100 × 80 = 8,000 bytes).

## Why a Stack?

Undo must reverse the newest action first. A stack removes the last item added, which is exactly that rule. A queue would undo the oldest edit instead, and other structures need extra searching or shifting.

## Limitations

- Fixed capacity of 100 actions (`MAX`)
- Undo removes the record of an action and reports it; it does not rewrite a real document

## Future Work

- Redo using a second stack
- Dynamic capacity with a linked list or resizable array
- Store old text and position so Undo restores the document
- Limit history to the last N actions
- Group fast typing into one Undo step
- GUI with Ctrl+Z / Ctrl+Y
- Save history to a file
