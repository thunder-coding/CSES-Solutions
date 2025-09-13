#include <cstdint>
#include <iostream>

int main() {
  uint32_t n;
  std::cin >> n;
  for (uint32_t i = 0; i != (1 << n); i++) {
    uint32_t j = i ^ (i >> 1);
    for (uint32_t k = 0; k != n; k++) {
      std::cout << ((j & (1 << (n - k - 1))) ? '1' : '0');
    }
    std::cout << "\n";
  }
}
