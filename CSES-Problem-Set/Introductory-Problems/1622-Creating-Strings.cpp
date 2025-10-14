#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>

inline uint32_t fact(const uint32_t n) {
  uint32_t prod = 1;
  for (uint32_t i = n; i != 0; i--) {
    prod *= i;
  }
  return prod;
}

int main() {
  std::string in;
  std::cin >> in;
  std::map<char, int> count;
  for (const auto &ch : in) {
    count[ch]++;
  }
  int i = 0;
  uint32_t c = fact(in.size());
  for (const auto &[ch, j] : count) {
    for (int k = 0; k != j; k++) {
      in[i++] = ch;
    }
    c /= fact(j);
  }
  std::cout << c << "\n";
  std::string out = in;
  do {
    std::cout << out << "\n";
    std::next_permutation(out.begin(), out.end());
  } while (out != in);
}
