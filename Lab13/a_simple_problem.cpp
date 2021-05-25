#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  ll a[n + 1], b[n], opt[n + 1];
  a[0] = b[0] = opt[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> b[i];
  }
  opt[1] = a[1];
  for (int i = 2; i <= n; i++) {
    opt[i] = min(opt[i - 1] + a[i], opt[i - 2] + b[i - 1]);
  }
  cout << opt[n];
  return 0;
}