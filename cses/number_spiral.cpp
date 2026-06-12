#include <iostream>
using namespace std;

int main() {
  long int t;
  long int x, y;

  cin >> t;

  for (long int i = 0; i < t; i++) {
    long int ans = 1;
    long int size = 1;
    long int diff = 1;
    cin >> x;
    cin >> y;

    if (x == y) {
      ans = (x * x) - y + 1;
    } else if (x > y && x % 2 == 0) {
      ans = (x * x) - y + 1;
    } else if (x > y && x % 2 == 1) {
      size = (2 * x) - 1;
      diff = size - y;
      ans = (x * x) - diff;
    } else if (y > x && y % 2 == 1) {
      ans = (y * y) - x + 1;
    } else if (y > x && y % 2 == 0) {
      size = (2 * y) - 1;
      diff = size - x;
      ans = (y * y) - diff;
    }
    cout << ans << endl;
  }

  return 0;
}
