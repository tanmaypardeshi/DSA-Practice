#include<iostream>
#include<vector>
using namespace std;

void print_array(vector<int>&);
void merge_sort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);

int main() {
	vector<int> arr;
	int n;

	cout<<"Enter the number of elements: ";
	cin>>n;

	for(int i = 0; i < n; i++) {
		int temp;
		cout<<"Enter value for arr["<<i<<"]: ";
		cin>>temp;
		arr.push_back(temp);
	}

	cout<<"\nOriginal array is: ";
	print_array(arr);

	merge_sort(arr, 0, n - 1);

	cout<<"Sorted array is: ";
	print_array(arr);
	cout<<endl;
}

void print_array(vector<int>& arr) {
	for(int i = 0; i < arr.size(); i++) {
		if(i == arr.size() - 1) {
			cout<<arr[i]<<endl;
			return;
		}
		cout<<arr[i]<<", ";
	}
}

void merge_sort(vector<int>& arr, int left, int right) {
	if(left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int l1 = left;
    int l2 = mid + 1;

    while (l1 <= mid && l2 <= right) {
        if (arr[l1] <= arr[l2]) {
            temp.push_back(arr[l1]);
            l1++;
        } else {
            temp.push_back(arr[l2]);
            l2++;
        }
    }

    while (l1 <= mid) {
        temp.push_back(arr[l1]);
        l1++;
    }

    while (l2 <= right) {
        temp.push_back(arr[l2]);
        l2++;
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[left + i] = temp[i];
    }
}
