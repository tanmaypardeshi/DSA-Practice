// Count the occurrences of an anagram in a string

#include<bits/stdc++.h>
using namespace std;

int main() {
    int i = 0, j = 0, count = 0, ans = 0;
    string main_string, sub_string;
    map<char, int> frequency_map;

    cout<<"Enter main string:- ";
    cin>>main_string;

    cout<<"Enter sub-string:- ";
    cin>>sub_string;

    for(char ch: sub_string) {
        frequency_map[ch]++;
    }

    count = frequency_map.size();

    while(j < main_string.length()) {
        char ch = main_string[j];
        if(frequency_map.find(ch) != frequency_map.end()) {
            frequency_map[ch]--;
            if(frequency_map[ch] == 0) {
                count--;
            }
        }
        if(j - i + 1 < sub_string.length()) {
            j++;
        } else if(j - i + 1 == sub_string.length()) {
            if(count == 0) {
                ans++;
            }
            char temp = main_string[i];
            if(frequency_map.find(temp) != frequency_map.end()) {
                frequency_map[ch]++;
                if(frequency_map[ch] == 1) {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    cout<<"Occurences of anagram:- "<<ans<<endl;
    return 0;
}