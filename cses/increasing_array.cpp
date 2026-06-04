#include <iostream>
#include <vector>
using namespace std;

int main() {
  long int n, prev, moves, temp;
  vector<int> arr;

  cin >> n;

  for (long int i = 0; i < n; i++) {
    cin >> temp;
    arr.push_back(temp);
  }

  prev = arr[0];
  moves = 0;

  for (long int i = 1; i < n; i++) {

    if (arr[i] < prev) {
      long int diff = prev - arr[i];
      arr[i] += diff;
      moves += diff;
    }
    prev = arr[i];
  }

  cout << moves;

  return 0;
}
