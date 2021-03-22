#include <iostream>
#include <string>
using namespace std;

int total, curidx, btchange, maxbeauty;
int appear[26];
bool upper[26], alb[26];
int pairings[26][26];

void findmax(int index, int beauty) {
  if (index >= total) {
    return;
  }
  findmax(index + 1, beauty);
  curidx = appear[index];
  btchange = 0;
  for (int i = 0; i < 26; i++) {
    if (curidx == i || pairings[curidx][i] == 0) {
      continue;
    }
    if (upper[i]) {
      btchange -= pairings[curidx][i];
    } else {
      btchange += pairings[curidx][i];
    }
  }
  if (btchange <= 0) {
    return;
  }
  beauty += btchange;
  maxbeauty = maxbeauty > beauty ? maxbeauty : beauty;
  upper[curidx] = true;
  findmax(index + 1, beauty);
  upper[appear[index]] = false;
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  string s;
  cin >> t;
  while (t--) {
    maxbeauty = total = 0;
    for (int i = 0; i < 26; i++) {
      upper[i] = false;
    }
    for (int i = 0; i < 26; i++) {
      alb[i] = false;
      for (int j = 0; j < 26; j++) {
        pairings[i][j] = 0;
      }
    }
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i' ||
          s[i] == 'o') {
        continue;
      }
      alb[s[i] - 97] = true;
    }
    for (int i = 0; i < 26; i++) {
      if (alb[i]) {
        appear[total++] = i;
      }
    }
    for (int i = 1; i < s.length(); i++) {
      if (alb[s[i] - 97] && alb[s[i - 1] - 97] && s[i] != s[i - 1]) {
        pairings[s[i - 1] - 97][s[i] - 97]++;
        pairings[s[i] - 97][s[i - 1] - 97]++;
      }
    }
    findmax(0, 0);
    cout << maxbeauty << '\n';
  }
  return 0;
}