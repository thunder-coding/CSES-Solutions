#include <array>
#include <cstdint>
#include <iostream>

constexpr uint64_t power(const uint64_t base, const uint64_t exp) {
  uint64_t prod = 1;
  for (uint64_t i = 0; i != exp; i++) {
    prod *= base;
  }
  return prod;
}
constexpr uint64_t base = power(10, 9) + 7;

constexpr std::array<uint64_t, 64> precompute() {
  std::array<uint64_t, 64> precomputed;
  precomputed[0] = 2;
  for (uint64_t i = 1; i != precomputed.size(); i++) {
    precomputed[i] = power(precomputed[i - 1], 2) % base;
  }
  return precomputed;
}

int main() {
  uint64_t n;
  std::cin >> n;
  const auto precomputed = precompute();
  uint64_t ans = 1;
  for (uint64_t i = 0; i != 64; i++) {
    if ((1 << i) & n) {
      ans *= precomputed[i];
      ans %= base;
      n ^= (1 << i);
    }
    if (n == 0) {
      break;
    }
  }
  std::cout << ans;
}
