#include <iostream>
#include <string>
using namespace std;

struct Node {
  int beauty;
  int current;
  bool upper[26];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, rear, front, newb, maxbeauty;
  Node **queue = new Node *[10000000], *temp, *cur;
  string s;
  cin >> t;
  while (t--) {
    rear = front = maxbeauty = 0;
    bool alb[26];
    int pairings[26][26];
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
      if (!alb[s[i] - 97]) {
        alb[s[i] - 97] = true;
      }
    }
    for (int i = 1; i < s.length(); i++) {
      if (alb[s[i] - 97] && alb[s[i - 1] - 97]) {
        pairings[s[i - 1] - 97][s[i] - 97]++;
        pairings[s[i] - 97][s[i - 1] - 97]++;
      }
    }
    temp = new Node{0, 0};
    for (int i = 0; i < 26; i++) {
      temp->upper[i] = false;
    }
    queue[rear++] = temp;
    while (rear > front) {
      cur = queue[front++];
      while (cur->current < 26) {
        if (alb[cur->current]) {
          temp = new Node{cur->beauty, cur->current + 1};
          for (int i = 0; i < 26; i++) {
            temp->upper[i] = cur->upper[i];
          }
          queue[rear++] = temp;
          newb = cur->beauty;
          for (int i = 0; i < 26; i++) {
            if (cur->current == i || pairings[cur->current][i] == 0) {
              continue;
            }
            if (cur->upper[i]) {
              newb -= pairings[cur->current][i];
            } else {
              newb += pairings[cur->current][i];
            }
          }
          if (newb <= cur->beauty) {
            break;
          }
          maxbeauty = newb > maxbeauty ? newb : maxbeauty;
          temp = new Node{newb, cur->current + 1};
          for (int i = 0; i < 26; i++) {
            temp->upper[i] = cur->upper[i];
          }
          temp->upper[cur->current] = true;
          queue[rear++] = temp;
          break;
        }
        cur->current++;
      }
      delete cur;
    }
    cout << maxbeauty << '\n';
  }
  return 0;
}