#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int value;
  long long obstacle;
};

struct TreeNode {
  long long food;
  long long pure_profit;
  vector<Node*> adjacant_nodes;
};

TreeNode** tree = new TreeNode*[200010];
long long hp = 0;
long long rest_time = 0;

bool compare(Node* a, Node* b) {
  if (tree[a->value]->pure_profit >= 0 && tree[b->value]->pure_profit >= 0) {
    return a->obstacle < b->obstacle;
  } else if (tree[a->value]->pure_profit < 0 && tree[b->value]->pure_profit < 0) {
    return (a->obstacle + tree[a->value]->pure_profit) > (b->obstacle + tree[b->value]->pure_profit);
  } else if (tree[a->value]->pure_profit >= 0) {
    return true;
  } else {
    return false;
  }
};

long long assign(TreeNode* parent, TreeNode* current) {
  for (int i = 0; i < current->adjacant_nodes.size(); i++) {
    if (tree[current->adjacant_nodes[i]->value] == parent) {
      current->pure_profit -= current->adjacant_nodes[i]->obstacle * 2;
      continue;
    }
    current->pure_profit += assign(current, tree[current->adjacant_nodes[i]->value]);
  }
  sort(current->adjacant_nodes.begin(), current->adjacant_nodes.end(), compare);
  return current->pure_profit;
}

void play(TreeNode* parent, TreeNode* current) {
  Node* parent_node = NULL;
  hp += current->food;
  for (int i = 0; i < current->adjacant_nodes.size(); i++) {
    if (tree[current->adjacant_nodes[i]->value] == parent) {
      parent_node = current->adjacant_nodes[i];
      continue;
    }
    if (current->adjacant_nodes[i]->obstacle > hp) {
      rest_time += current->adjacant_nodes[i]->obstacle - hp;
      hp = 0;
    } else {
      hp -= current->adjacant_nodes[i]->obstacle;
    }
    play(current, tree[current->adjacant_nodes[i]->value]);
  }
  if (parent_node != NULL) {
    if (parent_node->obstacle > hp) {
      rest_time += parent_node->obstacle - hp;
      hp = 0;
    } else {
      hp -= parent_node->obstacle;
    }
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, u, v;
  long long w, a;
  cin >> n;
  Node* temp_node;
  TreeNode *temp, *cur;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    tree[i] = new TreeNode{a, a};
  }
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> w;
    tree[u]->adjacant_nodes.push_back(new Node{v, w});
    tree[v]->adjacant_nodes.push_back(new Node{u, w});
  }
  tree[1]->pure_profit = assign(NULL, tree[1]);
  play(NULL, tree[1]);
  cout << rest_time;
  return 0;
}