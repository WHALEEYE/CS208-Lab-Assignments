#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string name;
  map<string, int> boy_id;
  map<string, int> girl_id;
  string boy_name[n], girl_name[n];
  int *queue = new int[n * n], front = 0, rear = 0, count[n], have_boy[n];
  int **boy_pref = new int *[n], **girl_pref = new int *[n],
      **gp_inv = new int *[n];
  for (int i = 0; i < n; i++) {
    cin >> name;
    boy_id.insert(pair<string, int>(name, i));
    boy_name[i] = name;
    count[i] = 0;
    queue[rear++] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> name;
    girl_id.insert(pair<string, int>(name, i));
    girl_name[i] = name;
    have_boy[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    boy_pref[i] = new int[n];
    for (int j = 0; j < n; j++) {
      cin >> name;
      boy_pref[i][j] = girl_id.at(name);
    }
  }
  for (int i = 0; i < n; i++) {
    girl_pref[i] = new int[n];
    gp_inv[i] = new int[n];
    for (int j = 0; j < n; j++) {
      cin >> name;
      girl_pref[i][j] = boy_id.at(name);
      gp_inv[i][boy_id.at(name)] = j;
    }
  }

  int temp, boyf, pgirl;
  while (rear > front) {
    temp = queue[front++];
    for (int i = count[temp]; i < n; i++) {
      pgirl = boy_pref[temp][i];
      boyf = have_boy[pgirl];
      if (boyf == -1) {
        have_boy[pgirl] = temp;
        count[temp] = i + 1;
        break;
      } else if (gp_inv[pgirl][temp] < gp_inv[pgirl][boyf]) {
        queue[rear++] = boyf;
        have_boy[pgirl] = temp;
        count[temp] = i + 1;
        break;
      }
      if (i == n - 1) {
        cout << "impossible";
        return 0;
      }
    }
  }

  int output[n];
  for (int i = 0; i < n; i++) {
    output[have_boy[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << boy_name[i] << ' ' << girl_name[output[i]] << '\n';
  }
}