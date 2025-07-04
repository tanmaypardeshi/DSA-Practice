// Find the maximum sum out of all sub-arrays of size k in an array of size n.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, temp, i = 0, j = 0, sum = 0, mx = INT16_MIN;
	vector<int> arr;

	cout << "Enter size of array:- ";
	cin >> n;
	
	cout << "Enter size of window:- ";
	cin >> k;

	cout << "Enter the array:- " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter array[" << i << "]:- ";
		cin >> temp;
		arr.push_back(temp);
	}

	while(j < n) {
		sum = sum + arr[j];
		if(j - i + 1 < k) {
			j++;
		} else if(j - i + 1 == k) {
			mx = max(mx, sum);
			sum = sum - arr[i];
			i++;
			j++;
		}
	}
	
	cout<<"Maximum sum of window size "<<k<<" is: "<<mx<<endl;
	return 0;
}