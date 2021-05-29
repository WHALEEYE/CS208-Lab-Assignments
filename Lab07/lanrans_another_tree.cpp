#include <algorithm>
#include <iostream>
using namespace std;

struct GraphNode {
  GraphNode* prt;
  int size;
};

struct Edge {
  GraphNode* v1;
  GraphNode* v2;
  int hasWeight;
};

bool comp_one(Edge* a, Edge* b) { return a->hasWeight > b->hasWeight; }

bool comp_zero(Edge* a, Edge* b) { return a->hasWeight < b->hasWeight; }

GraphNode* find(GraphNode* a) {
  if (a == a->prt) {
    return a;
  } else {
    a->prt = find(a->prt);
    return a->prt;
  }
}

void merge(GraphNode* a, GraphNode* b) {
  find(b)->size += find(a)->size;
  find(a)->prt = find(b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int Fib[30];
  Fib[0] = Fib[1] = 1;
  for (int i = 2; i < 30; i++) {
    Fib[i] = Fib[i - 1] + Fib[i - 2];
  }
  int n, m, t, u, v, w;
  bool rst;
  int max_cnt, min_cnt;
  GraphNode* temp;
  Edge* temp_edge;
  cin >> t;
  while (t--) {
    rst = false;
    cin >> n >> m;
    if (n > m + 1) {
      cout << "No" << '\n';
      continue;
    }
    GraphNode **grp_one = new GraphNode *[n + 1],
              **grp_zero = new GraphNode *[n + 1];
    grp_one[0] = new GraphNode{NULL, -1};
    grp_zero[0] = new GraphNode{NULL, -1};
    Edge **edgearr_one = new Edge *[m], **edgearr_zero = new Edge *[m];
    for (int i = 1; i <= n; i++) {
      temp = new GraphNode{NULL, 1};
      temp->prt = temp;
      grp_one[i] = temp;
      temp = new GraphNode{NULL, 1};
      temp->prt = temp;
      grp_zero[i] = temp;
    }
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      edgearr_one[i] = new Edge{grp_one[u], grp_one[v], w};
      edgearr_zero[i] = new Edge{grp_zero[u], grp_zero[v], w};
    }
    sort(edgearr_one, edgearr_one + m, comp_one);
    sort(edgearr_zero, edgearr_zero + m, comp_zero);
    max_cnt = min_cnt = 0;
    for (int i = 0; i < m; i++) {
      temp_edge = edgearr_one[i];
      if (find(temp_edge->v1) != find(temp_edge->v2)) {
        merge(temp_edge->v1, temp_edge->v2);
        if (temp_edge->hasWeight) {
          max_cnt++;
        }
      }
    }
    if (find(grp_one[1])->size != n) {
      cout << "No" << '\n';
      continue;
    }
    for (int i = 0; i < m; i++) {
      temp_edge = edgearr_zero[i];
      if (find(temp_edge->v1) != find(temp_edge->v2)) {
        merge(temp_edge->v1, temp_edge->v2);
        if (temp_edge->hasWeight) {
          min_cnt++;
        }
      }
    }
    for (int i = 0; i < 30; i++) {
      if (Fib[i] > max_cnt) {
        break;
      } else if (min_cnt <= Fib[i] && max_cnt >= Fib[i]) {
        rst = true;
        break;
      }
    }
    if (rst) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}
