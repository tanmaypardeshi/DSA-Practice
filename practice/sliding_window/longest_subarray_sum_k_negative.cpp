// Find the longest subarray that has sum k in an array of size n.
// The array can contain negative numbers as well.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, temp, mx = 0, sum = 0; // mx initialized to 0 for maximum length
    vector<int> arr;
    map<int, int> prefixSumIndex; // Map to store first occurrence of each prefix sum

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

    // Prefix sum approach for arrays with negative numbers
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Calculate prefix sum up to index i

        // Case 1: subarray from start to i adds to k
        if (sum == k) {
            mx = max(mx, i + 1); // Length is i+1 (0-indexed)
        }

        // Case 2: if (sum - k) was seen before, subarray from that point to i adds to k
        if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
            int prevIndex = prefixSumIndex[sum - k];
            mx = max(mx, i - prevIndex); // Length is current index - previous index
        }

        // Case 3: store the first occurrence of this sum to maximize subarray length
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
            prefixSumIndex[sum] = i;
        }
    }
    cout << "Maximum length is " << mx << endl;
    return 0;
}