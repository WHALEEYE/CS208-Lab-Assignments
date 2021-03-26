#include <iostream>
using namespace std;
struct graphNode;
struct Node;
long long assign(graphNode *prt, graphNode *cur, int dep);
void renew(graphNode *prt, graphNode *cur, long long beauty);

int n;
long long maxbeauty = 0;
long long curbeauty = 0;
long long treeWeight = 0;

struct Node {
  int value;
  Node *next;
  Node *pre;
};

struct graphNode {
  long long weight;
  Node *head;
  long long totalWeight;
};

graphNode **grp = new graphNode *[2000010];

long long assign(graphNode *prt, graphNode *cur, int dep) {
  curbeauty += dep * cur->weight;
  Node *curNode = cur->head;
  while (curNode->next != cur->head) {
    curNode = curNode->next;
    if (grp[curNode->value] == prt) {
      continue;
    }
    cur->totalWeight += assign(cur, grp[curNode->value], dep + 1);
  }
  cur->totalWeight += cur->weight;
  return cur->totalWeight;
};

void renew(graphNode *prt, graphNode *cur, long long beauty) {
  Node *curNode = cur->head;
  if (prt != NULL) {
    beauty += treeWeight - 2 * cur->totalWeight;
  }
  maxbeauty = maxbeauty > beauty ? maxbeauty : beauty;
  while (curNode->next != cur->head) {
    curNode = curNode->next;
    if (grp[curNode->value] == prt) {
      continue;
    }
    renew(cur, grp[curNode->value], beauty);
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
    grp[i] = new graphNode{wgt, tempNode, 0};
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
  grp[1]->totalWeight = treeWeight = assign(NULL, grp[1], 0);
  maxbeauty = curbeauty;
  renew(NULL, grp[1], curbeauty);
  cout << maxbeauty << '\n';
  return 0;
}