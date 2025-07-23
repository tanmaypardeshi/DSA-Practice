// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n.
// Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any
// order, but there's a constraint: there has to be a gap of at least n intervals between two tasks
// with the same label.
// Return the minimum number of CPU intervals required to complete all tasks.

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> arr;
    int size;

    cout << "Enter size of array:- ";
    cin >> size;

    cout << "Enter the array:- " << endl;
    for (int i = 0; i < size; i++) {
        char temp;
        cout << "Enter element " << i << " :- ";
        cin >> temp;
        arr.push_back(temp);
    }

    int n, ans = 0;

    cout << "Enter the value of n:- ";
    cin >> n;

    unordered_map<char, int> mp;
    mp.clear();

    for (const auto& x : arr) {
        mp[x]++;
    }

    priority_queue<pair<int, char>> max_heap;


    return 0;
}
