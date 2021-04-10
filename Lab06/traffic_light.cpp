#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int dest;
  long long weight;
};

struct GraphNode {
  int idx;
  bool visited;
  int a;
  int b;
  vector<Edge *> edges;
};

struct comp {
  bool operator()(Edge *a, Edge *b) { return a->weight > b->weight; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, u, v, w;
  cin >> n >> m;
  long long time = 0, temp_mod, temp_weight;
  priority_queue<Edge *, vector<Edge *>, comp> pq;
  GraphNode **grp = new GraphNode *[n + 1];
  GraphNode *cur_node, *temp_node;
  Edge *cur_edge, *temp_edge;
  long long *pi = new long long[n + 1];
  for (int i = 1; i <= n; i++) {
    grp[i] = new GraphNode{i, false};
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    grp[u]->edges.push_back(new Edge{v, w});
  }
  for (int i = 1; i <= n; i++) {
    cin >> grp[i]->a >> grp[i]->b;
  }
  pq.push(new Edge{1, 0});
  while (!pq.empty()) {
    cur_edge = pq.top();
    pq.pop();
    cur_node = grp[cur_edge->dest];
    if (cur_node->visited) {
      continue;
    }
    cur_node->visited = true;
    pi[cur_edge->dest] = cur_edge->weight;
    for (int i = 0; i < cur_node->edges.size(); i++) {
      temp_edge = cur_node->edges[i];
      temp_node = grp[temp_edge->dest];
      if (temp_node->visited) {
        continue;
      }
      temp_mod = (cur_edge->weight + temp_edge->weight) %
                 (temp_node->a + temp_node->b);
      if (temp_mod < temp_node->a) {
        pq.push(new Edge{temp_edge->dest, cur_edge->weight + temp_edge->weight +
                                              temp_node->a - temp_mod});
      } else {
        pq.push(
            new Edge{temp_edge->dest, cur_edge->weight + temp_edge->weight});
      }
    }
  }
  cout << pi[n];
  return 0;
}