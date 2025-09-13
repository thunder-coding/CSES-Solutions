#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
int main() {
  int64_t ans = std::numeric_limits<int64_t>::max();
  uint64_t n;
  std::cin >> n;
  std::vector<uint64_t> a(n, 0);
  for (uint64_t i = 0; i != n; i++) {
    std::cin >> a[i];
  }
  for (uint64_t i = 0; i != (1 << n); i++) {
    int64_t sum = 0;
    for (uint64_t j = 0; j != n; j++) {
      if ((1 << j) & i) {
        sum += a[j];
      } else {
        sum -= a[j];
      }
    }
    ans = std::min((sum < 0) ? -sum : sum , ans);
  }
  std::cout << ans << "\n";
}
