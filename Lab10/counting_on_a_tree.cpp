#include <algorithm>
#include <iostream>
using namespace std;

struct GraphNode {
  GraphNode *prt;
  long long size;
};

struct Edge {
  int v1;
  int v2;
  int weight;
};

bool comp(Edge *a, Edge *b) { return a->weight < b->weight; }

GraphNode *find(GraphNode *a) {
  if (a == a->prt) {
    return a;
  } else {
    a->prt = find(a->prt);
    return a->prt;
  }
}

void merge(GraphNode *a, GraphNode *b) {
  find(b)->size += find(a)->size;
  find(a)->prt = find(b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, u, v, w, maxq = 0;
  cin >> n >> m;
  GraphNode **grp = new GraphNode *[n + 1];
  Edge *temp_edge;
  Edge **edgearr = new Edge *[n - 1];
  int query[m];
  for (int i = 1; i <= n; i++) {
    grp[i] = new GraphNode{NULL, 1};
    grp[i]->prt = grp[i];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    edgearr[i] = new Edge{u, v, w};
  }
  sort(edgearr, edgearr + n - 1, comp);
  for (int i = 0; i < m; i++) {
    cin >> query[i];
    maxq = query[i] > maxq ? query[i] : maxq;
  }
  long long *pairs = new long long[maxq + 1]();
  for (int i = 0; i < n - 1; i++) {
    temp_edge = edgearr[i];
    if (temp_edge->weight > maxq) {
      break;
    }
    if (find(grp[temp_edge->v1]) != find(grp[temp_edge->v2])) {
      pairs[temp_edge->weight] +=
          find(grp[temp_edge->v1])->size * find(grp[temp_edge->v2])->size;
      merge(grp[temp_edge->v1], grp[temp_edge->v2]);
    }
  }
  for (int i = 1; i <= maxq; i++) {
    pairs[i] += pairs[i - 1];
  }
  for (int i = 0; i < m; i++) {
    cout << pairs[query[i]] << ' ';
  }
  return 0;
}