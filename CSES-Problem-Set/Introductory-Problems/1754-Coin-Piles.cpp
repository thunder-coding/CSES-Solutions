#include <cstdint>
#include <iostream>
#include <utility>
int main() {
  uint64_t t;
  for (std::cin >> t; t != 0; t--) {
    uint64_t a, b;
    std::cin >> a >> b;
    if (a < b) {
      std::swap(a, b);
    }
    if (a <= 2 * b && (2 * b - a) % 3 == 0) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}
