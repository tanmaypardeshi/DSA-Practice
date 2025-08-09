// Given an array of integers and two numbers k1 and k2. Find the sum of all elements between given two k1’th and k2’th smallest elements of the array. It
// may  be assumed that all elements of array are distinct.

// Example :
// Input : arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6  
// Output : 26          
// 3rd smallest element is 10. 6th smallest element 
// is 20. Sum of all element between k1 & k2 is
// 12 + 14 = 26 . 

#include <bits/stdc++.h>
using namespace std;

int find_kth_smallest(vector<int>, int);

int main() {
    vector<int> arr;
    int n;

    cout << "Enter size of array:- ";
    cin >> n;

    cout << "Enter the array:- " << endl;
    for (int i = 0; i < n; i++) {
        int temp;
        cout << "Enter element " << i << " :- ";
        cin >> temp;
        arr.push_back(temp);
    }

    int k1, k2;

    cout << "Enter k1:- ";
    cin >> k1;
    cout << "Enter k2:- ";
    cin >> k2;

    int first = find_kth_smallest(arr, k1);
    int second = find_kth_smallest(arr, k2);
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > first && arr[i] < second) {
            sum += arr[i];
        }
    }

    cout << "Sum is:- " << sum << endl;

    return 0;
}

int find_kth_smallest(vector<int> arr, int k) {
    priority_queue<int> max_heap;

    for (const auto& x : arr) {
        max_heap.push(x);
    }

    while (max_heap.size() > k) {
        max_heap.pop();
    }

    return max_heap.top();
}