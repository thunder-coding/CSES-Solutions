#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
int main() {
  uint32_t n;
  std::cin >> n;
  std::vector<uint32_t> sticks(n);
  for (uint32_t i = 0; i != n; i++) {
    std::cin >> sticks[i];
  }
  std::sort(sticks.begin(), sticks.end());
  uint64_t ans = 0;
  for (uint32_t i = (sticks.size() + 1) / 2; i != sticks.size(); i++) {
    ans += sticks[i];
  }
  for (uint32_t i = 0; i != sticks.size() / 2; i++) {
    ans -= sticks[i];
  }
  std::cout << ans << "\n";
}
