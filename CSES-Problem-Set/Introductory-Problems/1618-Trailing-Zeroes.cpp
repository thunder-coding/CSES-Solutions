#include <cstdint>
#include <iostream>
int main() {
  uint64_t n;
  std::cin >> n;
  uint64_t ans = 0;
  for (uint64_t tmp = 5; tmp <= n; tmp*= 5) {
    ans += (n / tmp);
  }
  std::cout << ans<< "\n";
}
