// Find the k largest elements

#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min heap to maintain k largest elements
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

    // Process each element using min heap approach
    for (auto x : arr) {
        min_heap.push(x); // Add current element to heap

        // Keep only k largest elements (remove smallest if heap size exceeds k)
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    // Output the k largest elements
    cout << "Elements are:- ";
    while (min_heap.size() > 0) {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    cout << endl;

    return 0;
}