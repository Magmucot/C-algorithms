# C++ Olympic Algorithms

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A focused collection of classic and essential algorithms for competitive programming and olympiads, implemented in clean and efficient C++. This repository serves as a personal reference and a learning resource for understanding the core ideas behind these fundamental algorithms.

## 📌 Table of Contents

- [Algorithm Categories](#-algorithm-categories)
- [Project Goals](#-project-goals)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation & Usage](#compilation--usage)
- [Algorithms Overview](#-algorithms-overview)
- [License](#-license)

## 📊 Algorithm Categories

The algorithms are organized into the following logical groups:

### 🔍 Graph Algorithms
- Depth-First Search (DFS) and its applications.
- Breadth-First Search (BFS) for shortest paths in unweighted graphs.
- Cycle detection in graphs.
- Topological Sorting of directed acyclic graphs.
- Finding Bridges in a graph.
- Minimum Spanning Tree algorithms (Kruskal/Prim).

### 🧵 String Algorithms
- The Knuth-Morris-Pratt (KMP) algorithm for pattern matching.
- Z-function and Prefix-function (Pi-function) for string preprocessing.

### 🌳 Tree Algorithms
- DFS traversals and properties of trees.
- Basic tree DP (implied in `dfs_tree.cpp`).

### 📈 Data Structures
- Segment Tree for efficient range queries and updates.

## 🎯 Project Goals

- **Clarity for Learning:** Code is written with readability in mind, including comments that explain the core logic and purpose, not just "what" but "why".
- **Olympiad Focus:** Implements standard, efficient versions of algorithms commonly used in programming competitions.
- **Minimal and Self-Contained:** Each implementation is focused on the algorithm itself, making it easy to extract and use as a snippet or a reference.

## 🛠 Getting Started

### Prerequisites

You only need a C++ compiler that supports the C++11 standard or later (like `g++`, `clang++`).

### Compilation & Usage

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/Magmucot/C-algorithms.git
    cd C-algorithms
    ```

2.  **Compile any algorithm:**
    For example, to compile the KMP algorithm:
    ```bash
    g++ KMP.cpp -o KMP
    ```

3.  **Run the compiled program:**
    ```bash
    ./KMP
    ```
    *(Note: Most files contain a `main()` function with a simple test case to demonstrate the algorithm.)*

## 🧠 Algorithms Overview

Here’s a quick guide to the files in this repository:

| File | Category | Description |
| :--- | :--- | :--- |
| `graphs.cpp` | Graph | Contains implementations of **DFS** and **BFS** for graph traversal, along with functions for cycle detection. |
| `dfs_tree.cpp` | Tree | Demonstrates the application of DFS on a tree structure. |
| `top_sort.cpp` | Graph | Implements **Topological Sorting** for directed acyclic graphs. |
| `bridges_and_dots.cpp` | Graph | An algorithm to find all **bridges** (critical edges) in an undirected graph using DFS. |
| `spanning_tree.cpp` | Graph | Provides an implementation for finding the **Minimum Spanning Tree** (likely Kruskal's algorithm). |
| `KMP.cpp` | String | The classic **Knuth-Morris-Pratt** algorithm for linear-time pattern matching. |
| `z-pi_func.cpp` | String | Implementations of the **Z-function** and the **Prefix-function** (Pi-function), fundamental for many string algorithms. |
| `segment_tree.cpp` | Data Structure | A basic implementation of a **Segment Tree** for range sum queries and point updates. |
| `css.cpp` | - | (This file name is ambiguous; it might be a typo or a sandbox file. Consider renaming it for clarity or removing it.) |

## 📜 License

Distributed under the MIT License. See the [LICENSE](LICENSE) file for more information.

---

**Developed with ❤️ by [Magmucot](https://github.com/Magmucot)**
