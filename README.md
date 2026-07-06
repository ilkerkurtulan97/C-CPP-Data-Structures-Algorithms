# C & C++ Data Structures, Algorithms, and System Programming

> **Author**: Ilker Kurtulan
> **Purpose**: To demonstrate my skills in C and C++ programming — from fundamentals to advanced topics — using clean, modular, and practical examples.

---

## About the Repository

This repository is a curated collection of C and C++ code examples created by **Ilker Kurtulan**, a Master's student in Embedded Systems Engineering. The goal is to showcase:

- My understanding of low-level and high-performance programming in C and C++.
- My grasp of data structures, algorithms, memory management, and system-level topics.
- My coding style, problem-solving ability, and software engineering practices.

Each file is designed to be **readable, educational, and testable**. The code is self-contained with explanatory comments and is suitable for beginners and professionals alike.

---

## Structure

The repository is organized into three top-level folders:

```
.
├── C/            # C solutions, exercises, and lecture-style examples
├── C++/          # C++ solutions, OOP demos, and lecture-style examples
└── algorithms/   # Algorithm & data-structure implementations / visualizers
```

### `C/`
Solved questions, experiments, and lecture-style notes written in C. Pointers,
memory, and low-level fundamentals live here.

- `playground.c` — pointer & function-pointer experiments.

### `C++/`
Solved questions and lecture-style examples written in C++, including small
object-oriented projects.

- `pointer.cpp`, `reverse_array_pointer.cpp` — pointer fundamentals.
- `sample_class.cpp`, `sample_work.cpp` — class / OOP basics.
- `car_rental/` — a small OOP project (inheritance, headers/sources, CMake).

### `algorithms/`
Standalone algorithm and data-structure implementations, including visualizers.

- `pathfinding_visualizer/` — pathfinding (A\*).
- `sorting_visualizer/` — sorting algorithms.
- `tree_visualizer/` — tree data structures.

---

## Building

Most sub-projects use CMake. A typical build:

```bash
cd algorithms/sorting_visualizer
cmake -B build
cmake --build build
```

Single-file examples can be compiled directly:

```bash
g++ C++/pointer.cpp -o pointer && ./pointer
gcc C/playground.c -o playground && ./playground
```

> Build outputs (`build/`) are git-ignored.
</content>
