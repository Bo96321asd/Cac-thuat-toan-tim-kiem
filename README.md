# Search Algorithms
![Author](https://img.shields.io/badge/Author:-Võ%20Hoàng%20Anh%20Tuấn-orange?style=flat-square) 
![University](https://img.shields.io/badge/University:-HCMUS-yellow?style=flat-square) 
![Language](https://img.shields.io/badge/Language-C++-lightgrey?style=flat-square)
# Table of Contents
+ [1. Introduction](#1-introduction)
+ [2. Content](#2-content)
---
# 1. Introduction
**Searching** is the process of determining whether a specific element exists within a dataset. If it exists, the goal is to identify its position.

Each search algorithm has its own advantages and disadvantages as a trade-off. This repository provides a summary of common search algorithms implemented in C++.

> **Note:** If you find any issues or inaccurate content, feel free to provide feedback.
---
# 2. Content
## 2.1. Linear Search
**Idea:** We iterate sequentially from the beginning of the array to the end (forward) or backwward. If the element is found, we return its index.
```cpp
int linear_search(const vector<int>& array, const int left, const int right, const int value) {
    for (int i = left; i <= right; i++) { 
        if (array[i] == value) {
            return i;  
        }
    }
    return INVALID_INDEX;
}
```
Time complexity: T(n) = O(n).
> **Advantages:**  
Easy implementation.  
No need for sorted data.  
> **Disadvantages:**  
Inefficient for large datasets.
## 2.2. Binary search 
> **Idea:** We check the middle element. If it is not the target, we recursively narrow the search range to the left or right half based on the comparison.
```C++
int search(const vector<int>& array, const int left, const int right, const int value) {
    if (left > right) { 
        return INVALID_INDEX; 
    }
    int middle = (right + left)/2;
    if (array[middle] == value) { 
        return middle; 
    }
    else if (array[middle] < value) { 
        return search(middle + 1, right, value);
    }
    else { 
        return search(left, middle - 1, value);
    }
}
```
Time complexity: T(n) = O(logn) (Not included sorting).
> **Advantages:**  
Highly efficient for large, sorted datasets.  
> **Disadvantages:**  
Requires the array to be sorted.  
Rearranging elements may lose original index positions. (fix: Using pair)
