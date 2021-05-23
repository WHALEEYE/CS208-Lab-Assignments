#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int cost[n + 1], beauty[n + 1];
  cost[0] = beauty[0] = 0;
  int opt[n + 1][m + 1];
  opt[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    opt[i][0] = 0;
  }
  for (int i = 1; i <= m; i++) {
    opt[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> beauty[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (cost[i] > j) {
        opt[i][j] = opt[i - 1][j];
      } else {
        opt[i][j] = max(opt[i - 1][j], opt[i - 1][j - cost[i]] + beauty[i]);
      }
    }
  }
  cout << opt[n][m];
  return 0;
}