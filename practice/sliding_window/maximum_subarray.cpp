// Given an array of size n, find the maximum from every subarray of size k.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, temp, i = 0, j = 0;
    vector<int> arr, ans;
    list<int> temp_list; // Deque-like structure to maintain potential maximums

    cout << "Enter size of array:- ";
    cin >> n;

    cout << "Enter size of window:- ";
    cin >> k;

    // Input array elements
    cout << "Enter the array:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter array[" << i << "]:- ";
        cin >> temp;
        arr.push_back(temp);
    }

    // Sliding window with deque approach for maximum in each window
    while (j < n) {
        // Remove smaller elements from back as they can't be maximum
        while (temp_list.size() > 0 && temp_list.back() < arr[j]) {
            temp_list.pop_back();
        }
        temp_list.push_back(arr[j]); // Add current element

        if (j - i + 1 < k) {
            j++; // Window size less than k, just expand
        }
        else if (j - i + 1 == k) {
            // Window size equals k, front element is maximum
            ans.push_back(temp_list.front());

            // If leftmost element is the maximum, remove it from deque
            if (arr[i] == temp_list.front()) {
                temp_list.pop_front();
            }
            i++; // Slide window: move left boundary
            j++; // Slide window: move right boundary
        }
    }

    // Output the result
    cout << "Answer is:- ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}