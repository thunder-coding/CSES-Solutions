#include <array>
#include <cstddef>
#include <iostream>
#include <string>

constexpr size_t N = 7;
std::array<std::array<bool, N>, N> vis;
size_t count = 0;
std::string line;

inline bool isinbound(const size_t x, const size_t y) {
  if (!(x >= 1 && x <= N && y >= 1 && y <= N)) {
    return false;
  }
  return !vis[y - 1][x - 1];
}

inline void dfs(size_t x, size_t y, size_t i) {
  if (i == (N * N - 1) && x == 1 && y == N) {
    count++;
    return;
  }
  if (x == 1 && y == N)
    return;
  // if (vis[N - 2][0] && vis[N - 1][1] && i != (N * N - 2)) return;
  if (!isinbound(x - 1, y) && !isinbound(x + 1, y) && isinbound(x, y - 1) &&
      isinbound(x, y + 1))
    return;
  if (isinbound(x - 1, y) && isinbound(x + 1, y) && !isinbound(x, y - 1) &&
      !isinbound(x, y + 1))
    return;

  vis[y - 1][x - 1] = true;
  if (isinbound(x - 1, y) && (line[i] == '?' || line[i] == 'L')) {
    dfs(x - 1, y, i + 1);
  }
  if (isinbound(x + 1, y) && (line[i] == '?' || line[i] == 'R')) {
    dfs(x + 1, y, i + 1);
  }
  if (isinbound(x, y - 1) && (line[i] == '?' || line[i] == 'U')) {
    dfs(x, y - 1, i + 1);
  }
  if (isinbound(x, y + 1) && (line[i] == '?' || line[i] == 'D')) {
    dfs(x, y + 1, i + 1);
  }
  vis[y - 1][x - 1] = false;
}

int main() {
  for (size_t i = 0; i != N; i++) {
    for (size_t j = 0; j != N; j++) {
      vis[i][j] = false;
    }
  }
  std::cin >> line;
  dfs(1, 1, 0);
  std::cout << count << "\n";
}
