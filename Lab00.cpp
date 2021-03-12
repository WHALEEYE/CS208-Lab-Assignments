#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, l;
  long long sum;
  cin >> t;
  while (t--) {
    sum = 0;
    cin >> n >> l;
    long long *fib = new long long[n + 1]();
    fib[0] = 1;
    for (int i = 1; i <= n; i++) {
      if (i <= l) {
        sum += fib[i - 1];
      } else {
        sum += fib[i - 1];
        sum -= fib[i - l - 1];
      }
      fib[i] = sum;
      fib[i] %= 998244353;
    }
    cout << fib[n] << '\n';
    delete[] fib;
  }
}