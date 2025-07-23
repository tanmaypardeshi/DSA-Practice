// Print the elements of an array in the increasing frequency if 2 numbers have same frequency then print the
// one which came first.

// Example:
// Input : arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
// Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6} . 

#include <bits/stdc++.h>
using namespace std;

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

    unordered_map<int, int> freq;
    priority_queue<pair<int, int>> max_heap;

    for (const auto& x : arr) {
        freq[x]++;
    }

    for (const auto& ele : freq) {
        max_heap.push({ ele.second, ele.first });
    }

    cout << "After sort, array is: ";

    while (max_heap.size() > 0) {
        int count = max_heap.top().first;
        for (int i = 0; i < count; i++) {
            cout << max_heap.top().second << " ";
        }
        max_heap.pop();
    }

    cout << endl;

    return 0;
}