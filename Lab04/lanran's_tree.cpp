#include <iostream>
using namespace std;

int n;
graphNode **grp = new graphNode *[2000010];
long long max = 0;

struct Node {
  int value;
  Node *next;
  Node *pre;
};

struct graphNode {
  long long weight;
  Node *head;
};

void assign(){};

void renew(graphNode *cur, long long beauty) {
  Node *curNode = cur->head->next;
  while (curNode != cur->head) {
    renew(grp[curNode->value], beauty);
    curNode = curNode->next;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int u, v;
  long long wgt;
  cin >> n;
  graphNode *temp, *cur;
  Node *tempNode;
  for (int i = 1; i < n + 1; i++) {
    tempNode = new Node{0, NULL, NULL};
    tempNode->next = tempNode->pre = tempNode;
    cin >> wgt;
    grp[i] = new graphNode{wgt, tempNode};
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    tempNode = new Node{u, grp[v]->head, grp[v]->head->pre};
    grp[v]->head->pre->next = tempNode;
    grp[v]->head->pre = tempNode;
    tempNode = new Node{v, grp[u]->head, grp[u]->head->pre};
    grp[u]->head->pre->next = tempNode;
    grp[u]->head->pre = tempNode;
  }
}