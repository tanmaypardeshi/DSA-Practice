// Find the maximum sum out of all sub-arrays of size k in an array of size n.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Initialize variables for array size, window size, and sliding window pointers
	int n, k, temp, i = 0, j = 0, sum = 0, mx = INT16_MIN;
	vector<int> arr;

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

	// Sliding window approach to find maximum sum subarray of size k
	while (j < n) {
		sum = sum + arr[j]; // Add current element to window sum

		if (j - i + 1 < k) {
			j++; // Window size is less than k, just expand
		}
		else if (j - i + 1 == k) {
			mx = max(mx, sum); // Window size equals k, update maximum sum
			sum = sum - arr[i]; // Remove leftmost element from sum
			i++; // Slide window: move left boundary
			j++; // Slide window: move right boundary
		}
	}

	cout << "Maximum sum of window size " << k << " is: " << mx << endl;
	return 0;
}