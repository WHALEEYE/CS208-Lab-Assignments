#include <iostream>
#include <queue>
using namespace std;

struct Letter {
  long long count;
};

struct comp {
  bool operator()(Letter *a, Letter *b) { return a->count > b->count; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string str;
  long long cnt;
  cin >> n;
  Letter *letter_table[26], *top1, *top2;
  while (n--) {
    cnt = 0;
    priority_queue<Letter *, vector<Letter *>, comp> pq;
    for (int i = 0; i < 26; i++) {
      letter_table[i] = new Letter{0};
    }
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
      letter_table[str[i] - 97]->count++;
    }
    for (int i = 0; i < 26; i++) {
      if (letter_table[i]->count) {
        pq.push(letter_table[i]);
      }
    }
    while (pq.size() > 1) {
      top1 = pq.top();
      cnt += top1->count;
      pq.pop();
      top2 = pq.top();
      cnt += top2->count;
      pq.pop();
      pq.push(new Letter{top1->count + top2->count});
    }
    cout << cnt << '\n';
  }
  return 0;
}