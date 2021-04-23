#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, t;
  long long rst = 0;
  cin >> n >> m;
  int process[n + 1][100];
  string op;
  int len = 99, leftmost = 99;
  bool changed = false;
  while (m) {
    process[0][len--] = m % 2;
    m /= 2;
  }
  leftmost = len + 1;
  for (int j = 0; j <= len; j++) {
    process[0][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    len = 99;
    cin >> op;
    if (op == "AND") {
      process[i][0] = 0;
    } else if (op == "OR") {
      process[i][0] = 1;
    } else if (op == "XOR") {
      process[i][0] = 2;
    }
    cin >> t;
    while (t) {
      process[i][len--] = t % 2;
      t /= 2;
    }
    leftmost = leftmost < (len + 1) ? leftmost : (len + 1);
    for (int j = 1; j <= len; j++) {
      process[i][j] = 0;
    }
  }

  int m_bit1, m_bit2;
  for (int i = leftmost; i < 100; i++) {
    m_bit1 = process[0][i];
    m_bit2 = 0;
    for (int j = 1; j <= n; j++) {
      switch (process[j][0]) {
        case 0:
          m_bit1 &= process[j][i];
          break;
        case 1:
          m_bit1 |= process[j][i];
          break;
        case 2:
          m_bit1 ^= process[j][i];
          break;
      }
    }
    if (changed || process[0][i]) {
      m_bit2 = 1 ^ m_bit1;
      for (int j = 1; j <= n; j++) {
        switch (process[j][0]) {
          case 0:
            m_bit2 &= process[j][i];
            break;
          case 1:
            m_bit2 |= process[j][i];
            break;
          case 2:
            m_bit2 ^= process[j][i];
            break;
        }
      }
    }
    if (!changed && process[0][i]) {
      changed = (m_bit2 >= m_bit1);
    }
    rst *= 2;
    rst += (m_bit1 | m_bit2);
  }
  cout << rst;
  return 0;
}