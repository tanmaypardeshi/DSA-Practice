// There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their
// lengths. We need to connect the ropes with minimum cost.

// For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
// 1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
// 2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
// 3) Finally connect the two ropes and all ropes have connected.

// Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. Other ways of connecting ropes would always
// have same or more cost. For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13
// and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38. . 

#include <bits/stdc++.h>
using namespace std;

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

    int total_cost = 0;

    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (const auto& x : arr) {
        min_heap.push(x);
    }

    while (min_heap.size() > 1) {
        int rope_1 = min_heap.top();
        min_heap.pop();
        int rope_2 = min_heap.top();
        min_heap.pop();
        int new_cost = rope_1 + rope_2;
        min_heap.push(new_cost);
        total_cost += new_cost;
    }

    cout << "Minimum cost of ropes is:- " << total_cost << endl;

    return 0;
}