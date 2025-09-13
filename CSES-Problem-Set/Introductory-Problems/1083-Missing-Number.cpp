#include <cstdint>
#include <iostream>

int main() {
  uint64_t n;
  std::cin >> n;
  int64_t sum = n;
  for (; n != 1; n--) {
    uint64_t tmp;
    std::cin >> tmp;
    sum -= tmp;
    sum += (n - 1);
  }
  std::cout << sum << "\n";
}
