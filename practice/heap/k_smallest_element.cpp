// Find the kth smallest element

#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> max_heap; // Max heap to maintain k smallest elements
    vector<int> arr;
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

    // Validate k value
    if (k > n) {
        cout << "k cannot exceed size of array, try again" << endl;
        return 0;
    }

    // Process each element using max heap approach
    for (auto x : arr) {
        max_heap.push(x); // Add current element to heap

        // Keep only k smallest elements (remove largest if heap size exceeds k)
        if (max_heap.size() > k) {
            max_heap.pop();
        }
    }

    // Top of max heap contains the kth smallest element
    cout << "kth largest element where k is " << k << " = " << max_heap.top() << endl;
    return 0;
}