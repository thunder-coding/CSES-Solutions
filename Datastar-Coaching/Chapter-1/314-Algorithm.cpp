#include <cstdint>
#include <iostream>
int main() {
  uint64_t n;
  std::cin >> n;
  while(true) {
    if (n == 1) {
      std::cout << 1 << "\n";
      break;
    }
    std::cout << n <<  " ";
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
  }
}
