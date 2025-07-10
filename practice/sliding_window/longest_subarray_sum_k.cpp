// Find the longest subarray that has sum k in an array of size n.
// The array contains positive numbers only.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialize variables for sliding window approach
    int n, k, temp, i = 0, j = 0, sum = 0, mx = 0;
    vector<int> arr;

    cout << "Enter size of array:- ";
    cin >> n;

    cout << "Enter sum:- ";
    cin >> k;

    // Input array elements
    cout << "Enter the array:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter array[" << i << "]:- ";
        cin >> temp;
        arr.push_back(temp);
    }

    // Sliding window approach for positive numbers only
    while (j < n) {
        sum = sum + arr[j]; // Add current element to window sum

        // If sum exceeds k, shrink window from left
        while (sum > k && i <= j) {
            sum = sum - arr[i]; // Remove leftmost element
            i++; // Move left boundary
        }

        // If sum equals k, update maximum length
        if (sum == k) {
            mx = max(mx, j - i + 1);
        }
        j++; // Expand window by moving right boundary
    }

    cout << "Size of longest subarray with sum " << k << " is " << mx << endl;

    return 0;
}