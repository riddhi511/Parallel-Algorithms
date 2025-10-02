# 🔢 Parallel Rank Sort (Assignment 2)

This program implements **Parallel Rank Sort** in C using process-based parallelism.  
The algorithm merges two sorted lists into a single sorted list by computing the **rank of each element** in parallel, then placing it in the correct position in the final merged array.

---

## 📘 Problem Description
- Input: Two sorted integer lists.  
- Task: Merge them into a single sorted list.  
- Approach: Each process independently computes the rank of its assigned element in both lists.  
- Output: A fully merged sorted list.

---

## 🧠 Key Concepts
- **Rank Computation**: Each element’s rank is determined by how many elements in the other list are smaller.  
- **Parallel Execution**: Rank calculations are distributed among multiple processes, reducing runtime.  
- **DSA Connection**: This is a fundamental **sorting/merging problem**, extended with **parallel computation** to optimize performance.

---

## 📊 Example

Input:
List A = [2, 5, 8]
List B = [1, 4, 9]


Parallel Rank Computation:
- 2 → rank 1
- 5 → rank 3
- 8 → rank 5
- 1 → rank 0
- 4 → rank 2
- 9 → rank 6

Output:

Merged List = [1, 2, 4, 5, 8, 9]


---

## ⚡ Efficiency
- Sequential merging: **O(n + m)** comparisons.  
- Parallel rank sort: **O(log(n + m))** steps (with enough processors).  
- Demonstrates how **parallelization reduces runtime** for large datasets.

---

## 🛠 How to Run

```bash
gcc assignment2.c -o rank_sort
./rank_sort
