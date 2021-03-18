#include <iostream>
using namespace std;

struct Node {
  int level;
  int w1, w2, w3;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Node *root, *temp, *cur;
  Node **happened = new Node *[1000000];
  Node **queue = new Node *[1000000];
  int s, n, m, rear, front, casenum, tmp;
  bool dup, poss;
  int t;
  cin >> t;
  while (t--) {
    cin >> s >> n >> m;
    if (n < m) {
      tmp = n;
      n = m;
      m = tmp;
    }
    if (s % 2 == 1) {
      cout << "impossible" << '\n';
      continue;
    }
    poss = false;
    rear = front = casenum = 0;
    temp = new Node{0, s, 0, 0};
    queue[rear++] = temp;
    happened[casenum++] = temp;
    while (rear > front) {
      cur = queue[front++];
      if (cur->w1 != 0) {
        if (cur->w2 != n) {
          dup = false;
          tmp = (n - cur->w2) < cur->w1 ? (n - cur->w2) : cur->w1;
          if (cur->w1 - tmp == cur->w2 + tmp) {
            poss = true;
            cout << cur->level + 1 << '\n';
            break;
          }
          temp =
              new Node{cur->level + 1, cur->w1 - tmp, cur->w2 + tmp, cur->w3};
          for (int i = 0; i < casenum; i++) {
            if (temp->w1 == happened[i]->w1 && temp->w2 == happened[i]->w2) {
              dup = true;
              break;
            }
          }
          if (!dup) {
            happened[casenum++] = temp;
            queue[rear++] = temp;
          }
          if (cur->w3 != m) {
            dup = false;
            tmp = (m - cur->w3) < cur->w1 ? (m - cur->w3) : cur->w1;
            temp =
                new Node{cur->level + 1, cur->w1 - tmp, cur->w2, cur->w3 + tmp};
            for (int i = 0; i < casenum; i++) {
              if (temp->w1 == happened[i]->w1 && temp->w2 == happened[i]->w2) {
                dup = true;
                break;
              }
            }
            if (!dup) {
              happened[casenum++] = temp;
              queue[rear++] = temp;
            }
          }
        }
      }
      if (cur->w2 != 0) {
        dup = false;
        temp = new Node{cur->level + 1, cur->w1 + cur->w2, 0, cur->w3};
        for (int i = 0; i < casenum; i++) {
          if (temp->w1 == happened[i]->w1 && temp->w2 == happened[i]->w2) {
            dup = true;
            break;
          }
        }
        if (!dup) {
          happened[casenum++] = temp;
          queue[rear++] = temp;
        }
        if (cur->w3 != m) {
          dup = false;
          tmp = (m - cur->w3) < cur->w2 ? (m - cur->w3) : cur->w2;
          temp =
              new Node{cur->level + 1, cur->w1, cur->w2 - tmp, cur->w3 + tmp};
          for (int i = 0; i < casenum; i++) {
            if (temp->w1 == happened[i]->w1 && temp->w2 == happened[i]->w2) {
              dup = true;
              break;
            }
          }
          if (!dup) {
            happened[casenum++] = temp;
            queue[rear++] = temp;
          }
        }
      }
      if (cur->w3 != 0) {
        dup = false;
        if (cur->w1 + cur->w3 == cur->w2) {
          poss = true;
          cout << cur->level + 1 << '\n';
          break;
        }
        temp = new Node{cur->level + 1, cur->w1 + cur->w3, cur->w2, 0};
        for (int i = 0; i < casenum; i++) {
          if (temp->w1 == happened[i]->w1 && temp->w2 == happened[i]->w2) {
            dup = true;
            break;
          }
        }
        if (!dup) {
          happened[casenum++] = temp;
          queue[rear++] = temp;
        }
        if (cur->w2 != n) {
          dup = false;
          tmp = (n - cur->w2) < cur->w3 ? (n - cur->w2) : cur->w3;
          if (cur->w1 == cur->w2 + cur->w3) {
            poss = true;
            cout << cur->level + 1 << '\n';
            break;
          }
          temp =
              new Node{cur->level + 1, cur->w1, cur->w2 + tmp, cur->w3 - tmp};
          for (int i = 0; i < casenum; i++) {
            if (temp->w1 == happened[i]->w1 && temp->w2 == happened[i]->w2) {
              dup = true;
              break;
            }
          }
          if (!dup) {
            happened[casenum++] = temp;
            queue[rear++] = temp;
          }
        }
      }
    }
    if (!poss) {
      cout << "impossible" << '\n';
    }
  }
  return 0;
}