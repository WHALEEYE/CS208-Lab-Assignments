#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

struct Task {
  ll st;
  ll ed;
  ll sc;
  bool finished;
};

struct comp {
  bool operator()(Task *a, Task *b) { return a->sc < b->sc; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  ll s, t, w, score, max = 0;
  priority_queue<Task *, vector<Task *>, comp> *pq_arr =
      new priority_queue<Task *, vector<Task *>, comp>[100000010];
  Task *temp;
  for (int i = 0; i < n; i++) {
    cin >> s >> t >> w;
    max = max > t ? max : t;
    temp = new Task{s, t, w, false};
    for (int j = s; j <= t; j++) {
      pq_arr[j].push(temp);
    }
  }
  for (int i = 1; i <= max; i++) {
    while (!pq_arr[i].empty()) {
      temp = pq_arr[i].top();
      if (!temp->finished) {
        temp->finished = true;
        score += temp->sc;
        break;
      }
      pq_arr[i].pop();
    }
  }
  cout << score;
  return 0;
}