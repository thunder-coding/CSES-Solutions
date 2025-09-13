#include <cstdint>
#include <iostream>
int main() {
  int t;
  for (std::cin >> t; t != 0; t--) {
    uint64_t y, x;
    uint64_t ans;
    std::cin >> y >> x;
    if (y > x) {
      if (y % 2 == 0) {
        ans = (y * y) - x + 1;
      } else {
        ans = (y - 1) * (y - 1) + x;
      }
    } else {
      if (x % 2 == 0) {
        ans = (x - 1) * (x - 1) + y;
      } else {
        ans = x * x - y + 1;
      }
    }
    std::cout << ans << "\n";
  }
}
