// Find the longest subarray that has sum k in an array of size n.
// The array can contain negative numbers as well.

// Find the longest subarray that has sum k in an array of size n.
// The array contains positive numbers only.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, temp, mx, sum = 0;
    vector<int> arr;
    map<int, int> prefixSumIndex;

    cout << "Enter size of array:- ";
    cin >> n;

    cout << "Enter sum:- ";
    cin >> k;

    cout << "Enter the array:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter array[" << i << "]:- ";
        cin >> temp;
        arr.push_back(temp);
    }

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Case 1: subarray from start to i adds to k
        if (sum == k) {
            mx = i + 1;
        }

        // Case 2: if (sum - k) was seen before, subarray from that point to i adds to k
        if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
            int prevIndex = prefixSumIndex[sum - k];
            mx = max(mx, i - prevIndex);
        }

        // Case 3: store the first occurrence of this sum
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
            prefixSumIndex[sum] = i;
        }
    }
    cout << "Maximum length is " << mx << endl;
    return 0;
}