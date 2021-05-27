#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int origin_task;

struct Task {
  int st;
  int ed;
  int pos;
  ll sc;
};

bool comp_1(Task* a, Task* b) {
  if (a->st == b->st) {
    return a->ed < b->ed;
  } else {
    return a->st < b->st;
  }
}
bool comp_2(Task* a, Task* b) { return a->sc > b->sc; }

bool place_task(int time[], int task_list[], Task* tasks[], int task_num,
                int pos) {
  origin_task = task_list[pos];
  if (time[pos] > tasks[task_num]->ed) {
    return false;
  } else if (origin_task == -1) {
    task_list[pos] = task_num;
    return true;
  } else if (tasks[origin_task]->ed < tasks[task_num]->ed) {
    return place_task(time, task_list, tasks, task_num, pos + 1);
  } else if (place_task(time, task_list, tasks, origin_task, pos + 1)) {
    task_list[pos] = task_num;
    return true;
  } else {
    return false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, s, t;
  ll w;
  cin >> n;
  Task* tasks[n];
  int task_list[n], time[n];
  tasks[0] = new Task{0, 0, 1, 0};
  for (int i = 0; i < n; i++) {
    cin >> s >> t >> w;
    tasks[i] = new Task{s, t, 0, w};
    task_list[i] = -1;
  }
  sort(tasks, tasks + n, comp_1);
  int pos_begin = 0, temp_time = 0;
  for (int i = 0; i < n; i++) {
    if (tasks[i]->st <= temp_time) {
      time[i] = ++temp_time;
    } else {
      time[i] = temp_time = tasks[i]->st;
    }
    for (int j = pos_begin; j < n; j++) {
      if (time[j] >= tasks[i]->st || j == n - 1) {
        tasks[i]->pos = pos_begin = j;
        break;
      }
    }
  }
  sort(tasks, tasks + n, comp_2);
  ll score = 0;
  for (int i = 0; i < n; i++) {
    if (place_task(time, task_list, tasks, i, tasks[i]->pos)) {
      score += tasks[i]->sc;
    }
  }
  cout << score;
}