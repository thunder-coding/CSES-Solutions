#include <cstdint>
#include <iostream>

int main() {
  uint64_t n;
  std::cin >> n;
  // In any 2x3 or 3x2 chess board, there are exactly 2 ways to put two knights that attack each other.
  // Now just calculate the number of such 2x3 and 3x2 sub-boards using:
  // 2 * (n - 1) * (n - 2)
  // ^---- 2 is multiplied as the boards may be horizontal or vertical
  // Thus the number of such positions where two knights are attacking each other:
  // 2 * 2 * (n - 1) * (n - 2)
  // ^---- 2 is multiplied as there are two configurations where knights attack each other in a 2x3 or 3x2 box
  //
  // Now, number of ways to select two places for knights to be in: 
  // C(n*n, 2)
  //
  // Thus answer is: 
  // C(n*n, 2) - 4 * (n - 1) * (n - 2)
  for (uint64_t k = 1; k <= n; k++) {
    std::cout << ((k * (k - 1)) / 2) * (k * (k + 1)) - 4 * (k - 1) * (k - 2) << "\n";
  }
}
