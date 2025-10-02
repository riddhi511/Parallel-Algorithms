# 🔍 Parallel Unique Element Search (Assignment 3)

This program demonstrates **parallel searching** for **unique elements** in a dataset using process-based concurrency in C.  
Each process checks whether its assigned element appears elsewhere in the array, allowing all uniqueness checks to run **simultaneously**.

---

## 📘 Problem Description
- **Input**: A list of integers (some may repeat).  
- **Task**: Identify all elements that occur **only once**.  
- **Approach**: Split the array across multiple processes; each process checks if its element is duplicated elsewhere.  
- **Output**: A list of all unique elements.

---

## 🧠 Key Concepts
- **Parallelism in Searching** → distribute the work of scanning across processes.  
- **Frequency Analysis** → each element is verified for uniqueness.  
- **DSA Connection** → relates to **searching and hashing problems**, but solved here using **parallel process checks**.  

---

## 📊 Example

Input:
[5, 3, 8, 3, 9, 5, 10]

Parallel Processes:
- Process 1 → 5 (duplicate)  
- Process 2 → 3 (duplicate)  
- Process 3 → 8 (unique ✅)  
- Process 4 → 3 (duplicate)  
- Process 5 → 9 (unique ✅)  
- Process 6 → 5 (duplicate)  
- Process 7 → 10 (unique ✅)

- Unique Elements = [8, 9, 10]

- 
---

## ⚡ Efficiency
- Sequential unique check: **O(n²)** comparisons in worst case.  
- Parallel approach: Each element is checked **concurrently**, significantly reducing execution time with enough processes.  
- Demonstrates how **parallel search techniques** can optimize standard DSA problems.  

---

## 🛠 How to Run
```bash
gcc assignment3.c -o unique_search
./unique_search


Output:
