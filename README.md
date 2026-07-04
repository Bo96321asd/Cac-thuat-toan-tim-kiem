# Các thuật toán tìm kiếm

![Tác giả](https://img.shields.io/badge/Tác%20giả:-Võ%20Hoàng%20Anh%20Tuấn-orange?style=flat-square)  
![Trường](https://img.shields.io/badge/Trường:-HCMUS-yellow?style=flat-square)   
![Ngôn ngữ](https://img.shields.io/badge/Ngôn%20ngữ-C++-lightgrey?style=flat-square)

# Mục lục
+ [1. Giới thiệu](#1-Giới-thiệu)
+ [2. Nội dung](#2-nội-dung)
---
# 1. Giới thiệu
**Tìm kiếm** là quá trình xác định xem một phần tử có tồn tại trong tập dữ liệu hay không. Nếu có tồn tại thì xác định vị trí của nó.

Mỗi thuật toán tìm kiếm sẽ đều có ưu điểm và nhược điểm riêng của nó như một sự đánh đổi (trade-off). 

Repository này sẽ tổng hợp các thuật toán tìm kiếm.

> **Lưu ý:** Nếu có những vấn đề hay nội dung sai lệch thì mong mọi người góp ý để mình cải thiện.

# 2. Nội dung
## 2.1. Tìm kiếm tuyến tính
> **Ý tưởng:** Chúng ta sẽ duyệt tuần tự từ đầu mảng đến cuối mảng hoặc ngược lại. Nếu tìm được thì trả về địa chỉ. 
```C++
int linear_search(const vector<int>& array, const int left, const int right, const int value) {
    for (int i = left; i <= right; i++) { 
        if (array[i] == value) {
            return i;  
        }
    }
    return INVALID_INDEX; 
}
```
Thời gian: T(n) = O(n).
> **Ưu điểm:**  
Dễ cài đặt.  
không phụ thuộc vào kiểu dữ liệu đầu vào.  
> **Nhược điểm:**  
Mảng lớn thì tốc độ sẽ chậm.
## 2.2. Tìm kiếm nhị phân 
> **Ý tưởng** Chúng ta sẽ sắp xếp lại mảng và xét vị trí giữa mảng có phải giá trị cần tìm không. Nếu không thì so sánh giá trị cần tìm với giá trị ở giữa mảng. Nếu giá trị cần tìm lớn hơn thì đệ quy sang bên phải không thì đệ quy sang trái.
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
Thời gian: T(n) = O(logn) (không bao gồm thời gian sắp xếp).
> **Ưu điểm:**  
Mảng lớn thì tốc độ sẽ tốt hơn tìm kiếm tuyến tính.   
> **Nhược điểm:**  
Cần sắp xếp mảng.
Mất vị trí ban đầu nếu sắp xếp trực tiếp trên mảng. (có thể dùng pair để lưu vị trí ban đầu)
