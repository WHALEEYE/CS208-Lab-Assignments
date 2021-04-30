#include <algorithm>
#include <iostream>
using namespace std;
int mid, s, k, p;

struct maj_rank {
  long long u;
  long long v;
  int order;
  int rev_cnt;
};

bool compare(maj_rank* a, maj_rank* b) {
  if (a->v == b->v) {
    return a->u < b->u;
  } else {
    return a->v < b->v;
  }
}

void combine(maj_rank* seq[], maj_rank* tseq[], int l, int mid, int r) {
  s = l, k = mid + 1, p = l;
  while (true) {
    if (s <= mid && k <= r) {
      if (seq[s]->u > seq[k]->u) {
        tseq[p] = seq[k];
        seq[k]->rev_cnt += (mid - s + 1);
        k++;
      } else {
        tseq[p] = seq[s];
        s++;
      }
    } else if (s == mid + 1) {
      tseq[p] = seq[k];
      k++;
    } else if (k == r + 1) {
      tseq[p] = seq[s];
      s++;
    }
    if (s == mid + 1 && k == r + 1) {
      for (int i = l; i <= r; i++) {
        seq[i] = tseq[i];
      }
      break;
    }
    p++;
  }
}

void mergeSort(maj_rank* seq[], maj_rank* tseq[], int l, int r) {
  if (l < r) {
    mid = (l + r) / 2;
    mergeSort(seq, tseq, l, mid);
    mid = (l + r) / 2;
    mergeSort(seq, tseq, mid + 1, r);
    mid = (l + r) / 2;
    combine(seq, tseq, l, mid, r);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, u, v;
  cin >> n;
  maj_rank *ranks[n], *temp[n];
  int happiness[n];
  for (int i = 0; i < n; i++) {
    cin >> u >> v;
    ranks[i] = new maj_rank{u, v, 0, 0};
    happiness[i] = 0;
  }
  sort(ranks, ranks + n, compare);
  for (int i = 0; i < n; i++) {
    ranks[i]->order = i;
  }
  mergeSort(ranks, temp, 0, n - 1);
  for (int i = 0; i < n; i++) {
    happiness[ranks[i]->order - ranks[i]->rev_cnt]++;
  }
  for (int i = 0; i < n; i++) {
    cout << happiness[i] << '\n';
  }
  return 0;
}