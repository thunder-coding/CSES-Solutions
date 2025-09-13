#include <cstdint>
#include <iostream>

int main() {
  uint64_t n;
  std::cin >> n;
  std::cout << n;
  for (std::cin >> n; n != 1;) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = (3 * n + 1);
    }
    std::cout << " " << n;
  }
  std::cout << "\n";
}
