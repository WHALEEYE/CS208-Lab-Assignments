#include <iostream>
using namespace std;

long long pow_2[61];
int expo;

int find(long long x) {
  for (int i = 0; i < 60; i++) {
    if (pow_2[i] - 1 <= x && pow_2[i + 1] - 1 > x) {
      return i;
    }
  }
}

long long numofL(long long x) {
  if (x == 0) {
    return 0;
  }
  expo = find(x);
  if (pow_2[expo] - 1 == x) {
    return pow_2[expo - 1];
  } else if (pow_2[expo] == x) {
    return pow_2[expo - 1] + 1;
  } else {
    return 1 + x - pow_2[expo] + numofL(2 * pow_2[expo] - x - 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long ini = 1;
  long long n, i, j;
  for (int i = 0; i < 61; i++) {
    pow_2[i] = ini;
    ini *= 2;
  }
  cin >> n;
  while (n--) {
    cin >> i >> j;
    cout << numofL(j) - numofL(i - 1) << '\n';
  }
  return 0;
}