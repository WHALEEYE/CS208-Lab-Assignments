#include <iostream>
using namespace std;
typedef long long ll;

struct LRN_pair {
  ll len;
  ll numofL;
  ll numofR;
  ll numofN;
};

LRN_pair **table = new LRN_pair *[62], *result = new LRN_pair{-1, 0, 0, 0};

void getNum(ll x, int state) {
  if (x == 0) {
    return;
  }
  for (int i = 0; i < 61; i++) {
    if (table[i]->len <= x && table[i + 1]->len > x) {
      switch (state % 3) {
        case 0:
          result->numofL += table[i]->numofL;
          result->numofR += table[i]->numofR;
          result->numofN += table[i]->numofN;
          break;
        case 1:
          result->numofL += table[i]->numofN;
          result->numofR += table[i]->numofL;
          result->numofN += table[i]->numofR;
          break;
        case 2:
          result->numofL += table[i]->numofR;
          result->numofR += table[i]->numofN;
          result->numofN += table[i]->numofL;
          break;
      }
      getNum(x - table[i]->len, state + 1);
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LRN_pair *temp_pair;
  table[0] = new LRN_pair{1, 1, 0, 0};
  for (int i = 1; i < 62; i++) {
    temp_pair = table[i - 1];
    table[i] =
        new LRN_pair{2 * temp_pair->len, temp_pair->numofL + temp_pair->numofN,
                     temp_pair->numofR + temp_pair->numofL,
                     temp_pair->numofN + temp_pair->numofR};
  }
  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    getNum(n, 0);
    cout << result->numofL << ' ' << result->numofR << ' ' << result->numofN
         << '\n';
    result->numofL = result->numofR = result->numofN = 0;
  }
  return 0;
}