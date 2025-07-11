// Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top 
// (According to their decreasing frequency) every time a new number is read. We basically need to print top k numbers 
// sorted by frequency when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency.

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    vector<int> arr;
    int n;

    cout << "Enter size of array:- ";
    cin >> n;

    cout << "Enter the array:- " << endl;
    for (int i = 0; i < n; i++) {
        int temp;
        cout << "Enter element " << i << " :- ";
        cin >> temp;
        arr.push_back(temp);
    }

    int k;

    cout << "Enter the value of k:- ";
    cin >> k;

    unordered_map<int, int> freq;

    for (auto x : arr) {
        freq[x]++;
    }

    priority_queue<pi, vector<pi>, greater<pi>> min_heap;

    for (const auto& x : freq) {
        min_heap.push({ x.second, x.first });
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    cout << "Top " << k << " elements are:- " << endl;
    while (min_heap.size() > 0) {
        cout << "Element = " << min_heap.top().second << ", Frequency = " << min_heap.top().first << endl;
        min_heap.pop();
    }

    return 0;
}