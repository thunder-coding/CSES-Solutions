#include <cstdint>
#include <iostream>
uint32_t l, m, r;
inline void solve(uint32_t l, uint32_t m, uint32_t r, uint32_t count) {
  if (count == 1) {
    std::cout << l << " " << r << "\n";
  } else {
    solve(l, r, m, count - 1);
    std::cout << l << " " << r << "\n";
    solve(m, l, r, count - 1);
  }
}
int main() {
  uint32_t n;
  std::cin >> n;
  // 2^n - 1
  std::cout << ((1 << n) - 1) << "\n";
  solve(1, 2, 3, n);
}
