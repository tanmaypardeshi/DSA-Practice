// Count the occurrences of an anagram in a string

#include<bits/stdc++.h>
using namespace std;

int main() {
    int i = 0, j = 0, count = 0, ans = 0;
    string main_string, sub_string;
    map<char, int> frequency_map; // Map to store character frequencies of pattern

    cout << "Enter main string:- ";
    cin >> main_string;

    cout << "Enter sub-string:- ";
    cin >> sub_string;

    // Build frequency map of the pattern (substring)
    for (char ch : sub_string) {
        frequency_map[ch]++;
    }

    count = frequency_map.size(); // Number of unique characters in pattern

    // Sliding window approach to find anagram occurrences
    while (j < main_string.length()) {
        char ch = main_string[j];

        // If character is part of pattern, decrease its frequency
        if (frequency_map.find(ch) != frequency_map.end()) {
            frequency_map[ch]--;
            if (frequency_map[ch] == 0) {
                count--; // One character frequency matched completely
            }
        }

        if (j - i + 1 < sub_string.length()) {
            j++; // Window size less than pattern size, expand window
        }
        else if (j - i + 1 == sub_string.length()) {
            // Window size equals pattern size
            if (count == 0) {
                ans++; // All character frequencies matched, found an anagram
            }

            // Slide window: remove leftmost character
            char temp = main_string[i];
            if (frequency_map.find(temp) != frequency_map.end()) {
                frequency_map[temp]++; // Restore frequency count
                if (frequency_map[temp] == 1) {
                    count++; // Character frequency no longer matches
                }
            }
            i++; // Move left boundary
            j++; // Move right boundary
        }
    }
    cout << "Occurences of anagram:- " << ans << endl;
    return 0;
}