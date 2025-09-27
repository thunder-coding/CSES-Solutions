#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
int main() {
  uint32_t n, m, k;
  std::cin >> n >> m >> k;
  std::vector<uint32_t> desired;
  std::vector<uint32_t> available;
  desired.resize(n);
  available.resize(m);
  for (uint32_t i = 0; i != n; i++) {
    std::cin >> desired[i];
  }
  for (uint32_t i = 0; i != m; i++) {
    std::cin >> available[i];
  }
  std::sort(desired.begin(), desired.end());
  std::sort(available.begin(), available.end());
  uint32_t ans = 0;
  for (uint32_t i = 0, j = 0; i != n && j != m;) {
    // Too rich
    if (desired[i] > available[j] + k) {
      j++;
      continue;
    }
    // To poor
    if (desired[i] + k < available[j]) {
      i++;
      continue;
    }
    ans++;
    i++;
    j++;
  }
  std::cout << ans << "\n";
}
