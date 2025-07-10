// Find the first negative number in every window of size k for an array of size n.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialize variables for sliding window
    int n, k, temp, i = 0, j = 0;
    vector<int> arr, temp_array, answer; // temp_array stores negative numbers in current window

    cout << "Enter size of array:- ";
    cin >> n;

    cout << "Enter size of window:- ";
    cin >> k;

    // Input array elements
    cout << "Enter the array:- " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter array[" << i << "]:- ";
        cin >> temp;
        arr.push_back(temp);
    }

    // Sliding window approach to find first negative in each window
    while (j < n) {
        // If current element is negative, add to temp array
        if (arr[j] < 0) {
            temp_array.push_back(arr[j]);
        }

        if (j - i + 1 < k) {
            j++; // Window size less than k, just expand
        }
        else if (j - i + 1 == k) {
            // Window size equals k, process current window
            if (temp_array.size() == 0) {
                answer.push_back(0); // No negative number in current window
            }
            else {
                answer.push_back(temp_array.front()); // First negative is at front
                // If leftmost element was the first negative, remove it from temp array
                if (arr[i] == temp_array.front()) {
                    temp_array.erase(temp_array.begin());
                }
            }
            i++; // Slide window: move left boundary
            j++; // Slide window: move right boundary
        }
    }

    // Output the result
    cout << "Answer is:- ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}