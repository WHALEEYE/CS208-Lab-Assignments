#include <algorithm>
#include <iostream>
using namespace std;

bool compare(int a, int b) { return a > b; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, a, s;
  long long max, sum1, sum2, temp1, temp2;
  bool alr1, alr2;
  cin >> t;
  while (t--) {
    alr1 = alr2 = false;
    sum1 = sum2 = max = temp1 = temp2 = 0;
    s = 0;
    cin >> n;
    long long *ipt = new long long[n];
    bool *dup = new bool[200010];
    for (int i = 0; i < 200010; i++) {
      dup[i] = false;
    }
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (!dup[a]) {
        ipt[s++] = a;
        dup[a] = true;
      }
    }
    sort(ipt, ipt + s, compare);
    if (s == 1) {
      cout << ipt[0] << '\n';
      return 0;
    }
    if (ipt[0] % ipt[1] != 0) {
      max = ipt[0] + ipt[1];
      for (int i = 2; i < s; i++) {
        if (ipt[0] % ipt[i] != 0 && ipt[1] % ipt[i] != 0) {
          max += ipt[i];
          break;
        }
      }
      cout << max << '\n';
    } else if (ipt[0] % ipt[1] == 0 && ipt[0] / ipt[1] < 3) {
      sum1 = ipt[0];
      sum2 = ipt[1];
      for (int i = 2; i < s; i++) {
        if (ipt[0] % ipt[i] != 0 && !alr1) {
          alr1 = true;
          sum1 += ipt[i];
          temp1 = ipt[i];
        } else if (ipt[1] % ipt[i] != 0 && !alr2) {
          alr2 = true;
          sum2 += ipt[i];
          temp2 = ipt[i];
        } else if (ipt[0] % ipt[i] != 0 && temp1 % ipt[i] != 0 && alr1) {
          sum1 += ipt[i];
          break;
        } else if (ipt[1] % ipt[i] != 0 && temp2 % ipt[i] != 0 && alr2) {
          sum2 += ipt[i];
          break;
        }
      }
      max = sum1 > sum2 ? sum1 : sum2;
      cout << max << '\n';
    } else if (ipt[0] % ipt[1] == 0 && ipt[0] / ipt[1] >= 3) {
      max = ipt[0];
      for (int i = 2; i < s; i++) {
        if (ipt[0] % ipt[i] != 0 && !alr1) {
          alr1 = true;
          max += ipt[i];
          temp1 = ipt[i];
        } else if (ipt[0] % ipt[i] != 0 && temp1 % ipt[i] != 0 && alr1) {
          max += ipt[i];
          break;
        }
      }
      cout << max << '\n';
    }
    delete[] ipt;
    delete[] dup;
  }
}