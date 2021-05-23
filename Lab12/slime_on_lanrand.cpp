#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  ll strength[n];
  for (int i = 0; i < n; i++) {
    cin >> strength[i];
  }
  if (n == 1) {
    cout << strength[0];
    return 0;
  }
  ll opt[n][n];
  ll total_weight[n][n];
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += strength[i];
    total_weight[0][i] = sum;
    total_weight[i][i] = strength[i];
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      total_weight[i][j] = total_weight[0][j] - total_weight[0][i - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    opt[i][i] = 0;
  }
  int end, begin, interval, divide;
  ll min, temp, totalW;
  for (interval = 1; interval < n; interval++) {
    for (begin = 0; begin < n - interval; begin++) {
      end = begin + interval;
      min = __INT64_MAX__;
      totalW = total_weight[begin][end];
      for (divide = begin; divide < end; divide++) {
        temp = opt[begin][divide] + opt[divide + 1][end] + totalW;
        min = temp < min ? temp : min;
      }
      opt[begin][end] = min;
    }
  }
  cout << opt[0][n - 1];
  return 0;
}