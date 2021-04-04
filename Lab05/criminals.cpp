#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  long long t;
  cin >> n >> m >> k >> t;
  int cri_pos[n], house_pos[m];
  for (int i = 0; i < n; i++) {
    cin >> cri_pos[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> house_pos[i];
  }
  sort(cri_pos, cri_pos + n);
  sort(house_pos, house_pos + m);
  int cur_cri = 0, not_arrested = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      if (cur_cri == n) {
        break;
      }
      if ((cri_pos[cur_cri]) - house_pos[i] <= t &&
          house_pos[i] - cri_pos[cur_cri] <= t) {
        cur_cri++;
        not_arrested++;
      } else if (cri_pos[cur_cri] < house_pos[i]) {
        j--;
        cur_cri++;
      } else {
        break;
      }
    }
  }
  cout << not_arrested;
}