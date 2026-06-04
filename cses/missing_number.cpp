#include <iostream>
using namespace std;

int main() {
  long int sum = 0, n, i, temp;
  cin >> n;

  for (i = 0; i < n - 1; i++) {
    cin >> temp;
    sum += temp;
  }
  long int grand_total = (n * (n + 1)) / 2;
  cout << grand_total - sum;
  return 0;
}
