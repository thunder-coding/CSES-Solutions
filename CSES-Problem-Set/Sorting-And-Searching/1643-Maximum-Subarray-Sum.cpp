#include <algorithm>
#include <cstdint>
#include <iostream>

int main() {
  uint32_t n;
  int64_t sum, min, tmp;
  int64_t ans = 0;
  std::cin >> n;
  std::cin >> tmp;
  sum = tmp;
  ans = sum;
  min = std::min((int64_t)0, sum);
  for (uint32_t i = 1; i < n; i++) {
    std::cin >> tmp;
    sum += tmp;
    ans = std::max(sum - min, ans);
    min = std::min(sum, min);
  }
  std::cout << ans << "\n";
}
