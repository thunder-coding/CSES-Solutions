#include <algorithm>
#include <iostream>
#include <map>
int main() {
  std::ios::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::cin >> n;
  std::map<int, int> map;
  int ans = 0;
  int prev = -1;
  for (int i = 0; i != n; i++) {
    int x;
    std::cin >> x;
    auto find = map.find(x);
    if (find != map.end() && prev < find->second) {
      prev = find->second;
    }
    ans = std::max(ans, i - prev);
    map[x] = i;
  }
  std::cout << ans << "\n";
}
