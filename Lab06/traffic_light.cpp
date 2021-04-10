#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int dest;
  int weight;
};

struct GraphNode {
  int idx;
  bool visited;
  int a;
  int b;
  vector<Edge *> edges;
};

GraphNode **grp = new GraphNode *[10010];
GraphNode *temp_node;
Edge *temp_edge;
long long temp_mod, temp_time, temp_min;
long long *pi = new long long[10010];
long long time = 0;

void find_min(GraphNode *cur) {
  temp_min = INT64_MAX;
  for (int i = 0; i < cur->edges.size(); i++) {
    temp_edge = cur->edges[i];
    temp_node = grp[temp_edge->dest];
    temp_time = time + temp_edge->weight;
    temp_mod = temp_time % (temp_node->a + temp_node->b);
    if (temp_mod < temp_node->a) {
      temp_time += temp_node->a - temp_mod;
    }
    pi[temp_edge->dest] =
        temp_time < pi[temp_edge->dest] ? temp_time : pi[temp_edge->dest];
    temp_min = temp_time < temp_min ? temp_time : temp_min;
  }
}

int main() {
  int n, m, u, v, w;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    grp[i] = new GraphNode{i, false};
    pi[i] = INT64_MAX;
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    grp[u]->edges.push_back(new Edge{v, w});
  }
  for (int i = 1; i <= n; i++) {
    cin >> grp[i]->a >> grp[i]->b;
  }
  pi[1] = 0;
}