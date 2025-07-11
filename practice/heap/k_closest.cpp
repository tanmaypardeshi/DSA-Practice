// Given an unsorted array and two numbers x and k, find k closest values to x.

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi; // Pair to store (distance, element)

int main() {
    vector<int> arr;
    int n;

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

    int k, x;
    vector<int> ans;
    priority_queue<pi> max_heap; // Max heap to store k closest elements

    cout << "Enter the value of k:- ";
    cin >> k;

    cout << "Enter the value of x:- ";
    cin >> x;

    // Process each element to find k closest elements
    for (auto ele : arr) {
        max_heap.push({ abs(x - ele), ele }); // Push distance and element

        // Keep only k elements in heap (remove farthest elements)
        while (max_heap.size() > k) {
            max_heap.pop();
        }
    }

    // Output the k closest elements
    cout << k << " closest elements to " << x << " are:- ";
    while (max_heap.size() > 0) {
        cout << max_heap.top().second << " "; // Print the element (not distance)
        max_heap.pop();
    }
    cout << endl;

    return 0;
}