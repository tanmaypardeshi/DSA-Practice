// Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. 
// For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min heap to maintain k+1 elements
    vector<int> arr, ans;
    int n, k;

    cout << "Enter size of array:- ";
    cin >> n;

    // Input array elements
    cout << "Enter the array:- " << endl;
    for (int i = 0; i < n; i++) {
        int temp;
        cout << "Enter element " << i << " :- ";
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "Enter value of k:- ";
    cin >> k;

    // Process each element using min heap of size k+1
    for (auto x : arr) {
        min_heap.push(x); // Add current element to heap

        // When heap size exceeds k, extract minimum (it's in correct sorted position)
        if (min_heap.size() > k) {
            ans.push_back(min_heap.top()); // Add smallest element to result
            min_heap.pop();
        }
    }

    // Extract remaining elements from heap (they are already sorted)
    while (min_heap.size() > 0) {
        ans.push_back(min_heap.top());
        min_heap.pop();
    }

    // Output the sorted array
    cout << "Answer is:- ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
