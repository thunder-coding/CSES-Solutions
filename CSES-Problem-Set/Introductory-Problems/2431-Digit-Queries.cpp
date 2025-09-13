#include <cstdint>
#include <iostream>
inline uint64_t pow10(uint64_t digits) {
  uint64_t ans = 1;
  while (digits != 0) {
    digits--;
    ans *= 10;
  }
  return ans;
}
int main() {
  uint64_t n;
  for (std::cin >> n; n != 0; n--) {
    uint64_t q;
    std::cin >> q;
    // digits = count of digits in the number we are looking at
    // count = count of numbers we have skipped
    uint64_t digits = 1, count = 9, skipped = 0;
    while (true) {
      if (q <= count * digits) {
        skipped += (q / digits);
        if (q % digits == 0) {
          std::cout << skipped % 10 << "\n";
        } else {
          std::cout << ((skipped + 1) / pow10(digits - (q % digits))) % 10 << "\n";
        }
        break;
      } else {
        q -= (count * digits);
        skipped += count;
        count *= 10;
        digits++;
      }
    }
  }
}
