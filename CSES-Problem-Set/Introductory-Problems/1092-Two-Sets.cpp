#include <cstdint>
#include <iostream>
int main() {
  uint32_t n;
  std::cin >> n;
  uint32_t l = n / 4;
  if (n % 4 == 0) {
    std::cout << "YES\n";
    std::cout << l * 2 << "\n";
    for (uint32_t i = 1; i <= l; i++) {
      std::cout << i << " ";
    }
    for (uint32_t i = 3 * l + 1; i <= 4 * l; i++) {
      std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << l * 2 << "\n";
    for (uint32_t i = l + 1; i <= 3 * l; i++) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  } else if (n % 4 == 3) {
    std::cout << "YES\n";
    std::cout << (2 * l + 2) << "\n";
    for (uint32_t i = 1; i <= l + 1; i++) {
      std::cout << i << " ";
    }
    for (uint32_t i = 3 * l + 4; i <= 4 * l + 3; i++) {
      std::cout << i << " ";
    }
    std::cout << (2 * l + 2) << " ";
    std::cout << "\n";
    std::cout << (2 * l + 1) << "\n";
    for (uint32_t i = l + 2; i <= 2 * l + 1; i++) {
      std::cout << i << " ";
    }
    for (uint32_t i = 2 * l + 3; i <= 3 * l + 3; i++) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  } else {
    std::cout << "NO\n";
  }
}
