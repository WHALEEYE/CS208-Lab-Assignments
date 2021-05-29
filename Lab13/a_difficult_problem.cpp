#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  ll a[n], ans = 0, sum[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0) {
      sum[i] = a[i];
    } else {
      sum[i] = sum[i - 1] + a[i];
    }
  }
  ll tmp = 1;
  while (tmp < sum[n - 1]) {
    tmp <<= 1;
  }
  while (tmp) {
    ans += tmp;
    bool opt[n][k];
    for (int j = 0; j < n; j++) {
      opt[j][0] = ((sum[j] & ans) == ans);
    }
    for (int j = 1; j < n; j++) {
      for (int h = 1; h <= (j < (k - 1) ? j : (k - 1)); h++) {
        opt[j][h] = false;
        for (int div = h - 1; div < j; div++) {
          if (opt[div][h - 1] && (((sum[j] - sum[div]) & ans) == ans)) {
            opt[j][h] = true;
            break;
          }
        }
      }
    }
    if (!opt[n - 1][k - 1]) {
      ans -= tmp;
    }
    tmp >>= 1;
  }
  cout << ans;
  return 0;
}