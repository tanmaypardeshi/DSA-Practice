#include<iostream>
#include<vector>
using namespace std;

void print_array(vector<int>&);
void bubble_sort(vector<int>&);

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

	bubble_sort(arr);

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

void bubble_sort(vector<int>& arr) {
	int n = arr.size();
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}