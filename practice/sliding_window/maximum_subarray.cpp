// Given an array of size n, find the maximum from every subarray of size k.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, temp, i = 0, j = 0;
    vector<int> arr, ans;
    list<int> temp_list;

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
        while(temp_list.size() > 0 && temp_list.back() < arr[j]) {
            temp_list.pop_back();
        }
        temp_list.push_back(arr[j]);

        if(j - i + 1 < k) {
            j++;
        } else if(j - i + 1 == k) {
            ans.push_back(temp_list.front());
            if(arr[i] == temp_list.front()) {
                temp_list.pop_front();
            }
            i++;
            j++;
        }
    }
    cout<<"Answer is:- ";
    for(auto x : ans) {
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}