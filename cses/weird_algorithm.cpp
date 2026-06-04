#include <iostream>
using namespace std;

int main() {
  long int n;
  cin >> n;

  while (n != 1) {
    cout << n << " ";
    if (n % 2 == 1) {
      n = n * 3 + 1;
    } else {
      n /= 2;
    }
  }
  cout << 1 << endl;
  return 0;
}
