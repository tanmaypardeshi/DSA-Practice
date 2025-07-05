// Find the first negative number in every window of size k for an array of size n.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, temp, i = 0, j = 0;
    vector<int> arr, temp_array, answer;

    cout << "Enter size of array:- ";
    cin >> n;

    cout << "Enter size of window:- ";
    cin >> k;

    cout << "Enter the array:- " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter array[" << i << "]:- ";
        cin >> temp;
        arr.push_back(temp);
    }

    while (j < n) {
        if (arr[j] < 0) {
            temp_array.push_back(arr[j]);
        }
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            if (temp_array.size() == 0) {
                answer.push_back(0);
            }
            else {
                answer.push_back(temp_array.front());
                if (arr[i] == temp_array.front()) {
                    temp_array.erase(temp_array.begin());
                }
            }
            i++;
            j++;
        }
    }

    cout << "Answer is:- ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}