#include <iostream>
#include <vector>
using namespace std;

int main() {
  long n;

  cin >> n;

  long sum = (n * (n + 1)) / 2;

  if (sum % 2 == 1) {
    cout << "NO" << endl;
    return 0;
  }

  long target = sum / 2;
  long running_sum = 0;

  vector<long> arr_1, arr_2;

  for (int i = n; i >= 1; i--) {
    running_sum += i;
    if (running_sum < target) {
      arr_1.push_back(i);
    } else if (running_sum == target) {
      arr_1.push_back(i);
    } else {
      running_sum -= i;
      arr_2.push_back(i);
    }
  }

  cout << "YES" << endl;
  cout << arr_1.size() << endl;
  for (const auto &a : arr_1) {
    cout << a << " ";
  }
  cout << "\n" << arr_2.size() << endl;
  for (const auto &a : arr_2) {
    cout << a << " ";
  }
  return 0;
}
