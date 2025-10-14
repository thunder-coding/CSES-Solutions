#include <cstdint>
#include <cstdlib>
#include <iostream>
int main() {
  uint32_t n;
  std::cin >> n;
  if (n == 1) {
    std::cout << "1\n";
    return EXIT_SUCCESS;
  }
  if (n == 4) {
    std::cout << "2 4 1 3\n";
    return EXIT_SUCCESS;
  }
  if (n < 4) {
    std::cout << "NO SOLUTION\n";
    return EXIT_SUCCESS;
  }
  for (uint32_t i = 0; i != n; i++) {
    if (i % 2 == 0) {
      std::cout << ((i / 2) + 1) << " ";
    } else {
      std::cout << ((n - 1) / 2) + 1 + (i / 2) + 1 << " ";
    }
  }
}
