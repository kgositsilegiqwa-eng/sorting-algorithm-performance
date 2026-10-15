# Sorting Algorithm Performance Comparison

## Overview

A C++ program that implements and compares Bubble Sort and Merge Sort by measuring their execution times across different input sizes. Both algorithms sort copies of the same randomly generated input data to provide a fair comparison.

## Features

- Generates random integer arrays with values between 0 and 9999.
- Implements Bubble Sort with an early-exit optimisation.
- Implements recursive Merge Sort using temporary sub-vectors.
- Tests input sizes of 100, 1,000, and 5,000 elements.
- Measures execution time using the C++ `clock()` function.
- Calculates theoretical growth estimates based on \(n^2\) and \(n\log_2(n)\).

## Algorithms

**Bubble Sort**
- Average and worst-case time complexity: O(n²).
- Repeatedly compares adjacent elements and swaps them when necessary.
- Stops early if a pass makes no swaps.

**Merge Sort**
- Time complexity: O(n log n).
- Recursively divides the input into smaller sections, sorts them, and merges the sorted sections.

## Technologies

- C++
- C++ Standard Library
- Vectors and recursion
- Random number generation
- Execution-time measurement

## How to Compile and Run

Compile using GCC:

```bash
g++ sorting_algorithm_performance.cpp -o sorting_benchmark
```

Run on Linux or Ubuntu:

```bash
./sorting_benchmark
```

On Windows:

```bash
sorting_benchmark.exe
```

## Learning Objectives

This project explores algorithm implementation, recursion, time complexity, execution-time measurement, and the impact of input size on sorting performance.

## Project Context

Developed as an academic programming project to practise sorting algorithms and algorithm analysis in C++.
