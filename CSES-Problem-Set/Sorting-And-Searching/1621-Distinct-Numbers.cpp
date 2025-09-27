#include <cstdint>
#include <iostream>
#include <set>
int main() {
  std::set<uint32_t> set;
  uint32_t t;
  for (std::cin >> t; t != 0; t--) {
    uint32_t n;
    std::cin >> n;
    set.emplace(n);
  }
  std::cout << set.size() << "\n";
}
