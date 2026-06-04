#include <iostream>
#include <string>
using namespace std;

int main() {
  string input_string;
  cin >> input_string;

  if (input_string.size() == 0 || input_string.size() == 1) {
    cout << input_string.size();
    return 0;
  }

  long int mx = 1, cntr = 1;
  char prev = input_string[0];

  for (long int i = 1; i < input_string.size(); i++) {
    if (input_string[i] == prev) {
      cntr++;
      mx = max(mx, cntr);
    } else {
      cntr = 1;
    }
    prev = input_string[i];
  }
  cout << mx << endl;

  return 0;
}
