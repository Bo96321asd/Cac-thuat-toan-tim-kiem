# Searching algorithms
![Author](https://img.shields.io/badge/Author:-Võ%20Hoàng%20Anh%20Tuấn-orange?style=flat-square) 
![University](https://img.shields.io/badge/University:-HCMUS-yellow?style=flat-square) 
![Language](https://img.shields.io/badge/Language-C++-lightgrey?style=flat-square)
# Table of contents
+ [1. Introduction](#1-introduction)
+ [2. Content](#2-content)
---
# 1. Introduction
**Searching** is the process of determining whether a specific element exists within a dataset. If it exists, the goal is to identify its position.

Each search algorithm has its own advantages and disadvantages as a trade-off. This repository provides a summary of common search algorithms implemented in C++.

> **Note:** If you find any issues or inaccurate content, feel free to provide feedback.
---
# 2. Content
## 2.1. Linear search
**Performance:**  
Time complexity: $O(n)$.    
Space complexity: $O(1)$.  
Advantages:  
Easy implementation.  
No need for sorted data.  
Disadvantages:  
Inefficient for large datasets.
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
## 2.2. Binary search 
**Performance:**  
Time complexity: $O(logn)$.  
Space complexity: $O(1)$.  
Advantages:  
Highly efficient for large, sorted datasets.   
Disadvantages:  
Requires the array to be sorted.  
Rearranging elements may lose their original indices. (Suggested: Using pair)
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
