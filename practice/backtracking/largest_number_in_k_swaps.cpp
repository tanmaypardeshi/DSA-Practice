// Given a string of digits, return the largest number in k swaps.

#include<bits/stdc++.h>
using namespace std;

void solve(string &, string &, int, int);

int main() {
    string num, ans;
    int k;

    cout<<"Enter a number:- ";
    cin>>num;

    ans = "";

    cout<<"Enter the number of swaps:- ";
    cin>>k;

    solve(num, ans, k, 0);

    cout<<"Largest number after k swaps is:- "<<ans<<endl;

    return 0;
}

void solve(string str, string ans, int k, int start) {
    // Base condition
    if(k == 0 || start = str.size()) {
        ans = s;
        return;
    }
}