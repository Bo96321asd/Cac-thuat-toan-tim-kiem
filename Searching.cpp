#include <bits/stdc++.h>

const int INVALID_INDEX = -1; 

using namespace std;

// Array implementations
void print_array(const vector<int>& array) {
    cout << "The array:\n";
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

// Search algorithms
class linear_search {
    private: 
    const vector<int>& array;
    public:
    linear_search(const vector<int>& input) : array(input) {}
    int search(const int left, const int right, const int value) {
        for (int i = left; i <= right; i++) { 
            if (array[i] == value) {
                return i;  
            }
        }
        return INVALID_INDEX; 
    }
};
class binary_search_manual {
    private: 
    vector<pair<int, int>> array;
    public:
    binary_search_manual(const vector<int>& input) {
        for (int i = 0; i < input.size(); i++) {
            array.push_back({input[i], i});
        }
        sort(array.begin(), array.end());
    }
    int search(const int left, const int right, const int value) {
        if (left > right) { 
            return INVALID_INDEX; 
        } 
        int middle = (right + left)/2;
        if (array[middle].first == value) { 
            return array[middle].second; 
        }
        else if (array[middle].first < value) { 
            return search(middle + 1, right, value);
        }
        else { 
            return search(left, middle - 1, value);
        }
    }
};

int main() {
    cout << "Enter the number of elements:\n";
    int size = 0;
    cin >> size;
    cout << "Enter the elements:\n";
    vector<int> array(size, 0);
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    print_array(array);
    cout << "Enter the range:\n";
    cout << "Left:\n";
    int left = 0;
    cin >> left;
    cout << "Right:\n";
    int right = 0;
    cin >> right;
    VALUE:
    cout << "Enter the value:\n";
    int value = 0;
    cin >> value;
    TYPE:
    cout << "Select type:\n";
    cout << "-1. Exit\n";
    cout << "0. Change value\n";
    cout << "1. Linear search\n";
    cout << "2. Binary search\n";
    int type = 0;
    cin >> type;
    switch(type) {
        case 0: {
            goto VALUE;
        }
        case 1: { 
            linear_search output_array(array);
            int index = output_array.search(left, right, value);
            if (index != INVALID_INDEX) {
                cout << "The value was found at index: " << index << "\n";
            }
            else {
                cout << "The value was not found\n";
            }
            goto TYPE;
        }
        case 2: { 
            int previous_left = left;
            int previous_right = right;
            binary_search_manual output_array(array);
            int index = output_array.search(previous_left, previous_right, value);
            if (index != INVALID_INDEX) {
                cout << "The value was found at index: " << index << "\n";
            }
            else {
                cout << "The value was not found\n";
            }
            goto TYPE;
        }
        default: {
            return 0;
        }
    }
}