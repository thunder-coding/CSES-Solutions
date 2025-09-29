#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
int main() {
  uint32_t n;
  std::cin >> n;
  std::vector<uint32_t> x(n);
  for (uint32_t i = 0; i != n; i++) {
    std::cin >> x[i];
  }
  std::sort(x.begin(), x.end());
  uint64_t ans = 1;
  for (uint32_t i = 0; i != x.size(); i++) {
    if (x[i] > ans) {
      std::cout << ans << "\n";
      return EXIT_SUCCESS;
    }
    ans += x[i];
  }
  std::cout << ans << "\n";
}
