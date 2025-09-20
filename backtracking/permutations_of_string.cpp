// Given a string, print all its permutations

#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

void solve(string &, int , vector<string> &);

int main() {
    string s;

    cout<<"Enter string:- ";
    cin>>s;

    vector<string> ans;

    solve(s, 0, ans);

    cout<<"Permutations are:- ";
    for(const auto &str: ans) {
        cout<<str<<" ";
    }
    cout<<endl;

    return 0;
}

void solve(string &s, int start, vector<string> &ans) {
    // Base condition
    if(start == s.size()) {
        ans.push_back(s);
        return;
    }

    unordered_set<char> used;

    for(int i = start; i < s.size(); i++) {
        if(used.find(s[i]) != used.end()) {
            continue;
        }
        used.insert(s[i]);
        swap(s[start], s[i]);
        solve(s, start + 1, ans);
        swap(s[start], s[i]);
    }

}