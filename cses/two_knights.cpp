// Two Knights Problem Intuition
//
// Goal: Count pairs of knights that do NOT attack each other on an n×n board.
//
// Approach: Total pairs - Attacking pairs
//
// Total pairs: Choose any 2 squares from n² squares = n²(n²-1)/2
//
// Attacking pairs:
// A knight attacks in an L-shape. Every attacking pair of knights
// fits exactly in a 2×3 or 3×2 rectangle, on opposite corners.
// Each such rectangle contributes exactly 2 attacking pairs (two sets of
// opposite corners).
//
// Number of 2×3 rectangles on n×n board = (n-1)(n-2)  [3 wide, 2 tall]
// Number of 3×2 rectangles on n×n board = (n-1)(n-2)  [2 wide, 3 tall]
//
// Total attacking pairs = 2 * (n-1)(n-2) * 2 = 4(n-1)(n-2)
//
// Answer = n²(n²-1)/2 - 4(n-1)(n-2)

#include <iostream>
using namespace std;

int main() {
  long int n;

  cin >> n;

  for (long int i = 1; i <= n; i++) {
    if (i == 1) {
      cout << 0 << endl;
      continue;
    }
    if (i == 2) {
      cout << 6 << endl;
      continue;
    }
    long int total = ((i * i) * (i * i - 1)) / 2;
    long int attacking_pairs = 4 * ((i - 2) * (i - 1));
    long int ans = total - attacking_pairs;
    cout << ans << endl;
  }
  return 0;
}
