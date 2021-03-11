#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, l;
  cin >> t;
  while (t--) {
    cin >> n >> l;
    long long *fib = new long long[n + 1]();
    fib[0] = 1;
    for (int i = 1; i <= n; i++) {
      int k = l < i ? l : i;
      for (int j = 1; j <= k; j++) {
        fib[i] += fib[i - j];
      }
      fib[i] %= 998244353;
    }
    cout << fib[n] << '\n';
    delete[] fib;
  }
}