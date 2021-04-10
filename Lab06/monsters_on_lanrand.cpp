#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, pos = false, neg = false;
  cin >> n;
  ll sum = 0, min = 0, a = 0, a_abs = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    a_abs = a > 0 ? a : -a;
    if (i == 0) {
      min = a_abs;
    } else {
      min = min < a_abs ? min : a_abs;
    }
    sum += a_abs;
    if (a > 0) {
      pos = true;
    } else if (a < 0) {
      neg = true;
    }
  }
  if (n == 1) {
    cout << a;
  } else if (pos ^ neg) {
    cout << sum - 2 * min;
  } else {
    cout << sum;
  }
  return 0;
}