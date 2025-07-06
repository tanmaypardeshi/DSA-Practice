// Find the longest subarray that has sum k in an array of size n.
// The array contains positive numbers only.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, temp, i = 0, j = 0, sum = 0, mx = 0;
    vector<int> arr;

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

    while (j < n) {
        sum = sum + arr[j];

        while (sum > k && i <= j) {
            sum = sum - arr[i];
            i++;
        }

        if (sum == k) {
            mx = max(mx, j - i + 1);
        }
        j++;
    }

    cout << "Size of longest subarray with sum " << k << " is " << mx << endl;

    return 0;
}