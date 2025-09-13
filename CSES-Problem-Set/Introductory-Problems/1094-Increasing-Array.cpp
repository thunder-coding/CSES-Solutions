#include <cstdint>
#include <iostream>
int main() {
  uint32_t n;
  uint64_t x = 0, maxx = 0, ans = 0;
  for(std::cin >> n; n != 0; n--) {
    std::cin >> x;
    if (x < maxx) {
      ans += (maxx - x);
    } else if (x > maxx) {
      maxx = x;
    }
  }
  std::cout << ans << "\n";
}
