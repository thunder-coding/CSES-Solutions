#include <iostream>
#include <limits>
#include <queue>
#include <vector>

int n;
std::vector<std::vector<int>> ans;
std::vector<std::vector<bool>> explored;
struct QueuedItem {
  int i, j;
  int val;
};
std::queue<QueuedItem> queue;


inline void solve(const int i, const int j, const int val) {
  if (i >= 1 && j >= 1 && i <= n && j <= n && !explored[i - 1][j - 1]) {
    explored[i - 1][j - 1] = true;
    queue.push({.i = i, .j = j, .val = val + 1});
    ans[i - 1][j - 1] = val + 1;
  }
}

int main() {
  std::cin >> n;
  ans.resize(n, {});
  explored.resize(n);
  for (int i = 0; i != n; i++) {
    ans[i].resize(n, std::numeric_limits<int>::max());
    explored[i].resize(n, false);
  }
  explored[0][0] = true;
  ans[0][0] = 0;
  explored[0][0] = true;
  queue.push({.i = 1, .j = 1, .val = 0});
  while (!queue.empty()) {
    const auto queued = queue.front();
    solve(queued.i - 1, queued.j + 2, queued.val);
    solve(queued.i - 1, queued.j - 2, queued.val);
    solve(queued.i + 1, queued.j + 2, queued.val);
    solve(queued.i + 1, queued.j - 2, queued.val);
    solve(queued.i - 2, queued.j + 1, queued.val);
    solve(queued.i - 2, queued.j - 1, queued.val);
    solve(queued.i + 2, queued.j + 1, queued.val);
    solve(queued.i + 2, queued.j - 1, queued.val);
    queue.pop();
  }
  for (int i = 0; i != n; i++) {
    for (int j = 0; j != n; j++) {
      std::cout << ans[i][j] << " ";
    }
    std::cout << "\n";
  }
}
