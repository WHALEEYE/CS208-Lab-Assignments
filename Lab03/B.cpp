#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int L, n;
string s;
int near[26][26];
int val_sum[26];
int ans;

struct edge {
  int val, to;
  edge(int to, int val) {
    this->to = to;
    this->val = val;
  }
};

vector<edge> a[26];

bool conso(char c) {
  return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

void dfs(int letter, int val) {
  // is lower case
  if (letter < 25) {
    dfs(letter + 1, val);
  }

  // is upper case
  if (val_sum[letter] > 0) {
    val += val_sum[letter];
    ans = std::max(ans, val);

    if (letter < 25) {
      // letters[letter] = 1;
      for (auto edge : a[letter]) {
        val_sum[edge.to] -= 2 * edge.val;
      }
      dfs(letter + 1, val);
      // letters[letter] = 0;
      for (auto edge : a[letter]) {
        val_sum[edge.to] += 2 * edge.val;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> L;
  while (L--) {
    ans = 0;
    memset(near, 0, sizeof(near));
    memset(val_sum, 0, sizeof(val_sum));
    for (int i = 0; i < 26; i++) {
      a[i].clear();
    }

    cin >> s;
    for (int i = 1; i < s.size(); i++) {
      if (conso(s[i]) && conso(s[i - 1])) {
        near[s[i] - 'a'][s[i - 1] - 'a']++;
      }
    }

    for (int i = 0; i < 26; i++)
      for (int j = 0; j < i; j++)
        if (conso(i + 'a') && conso(j + 'a')) {
          int cnt = near[i][j] + near[j][i];
          // cout<<i<<" "<<j<<" "<<val<<"\n";
          val_sum[i] += cnt;
          val_sum[j] += cnt;
          a[i].push_back(edge(j, cnt));
          a[j].push_back(edge(i, cnt));
        }
    // for (int i = 0; i < 26; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         cout << near[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    dfs(0, 0);
    cout << ans << "\n";
  }
}