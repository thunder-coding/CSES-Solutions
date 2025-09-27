#include <cstdint>
#include <iostream>
#include <set>

int main() {
  uint32_t n, m;
  std::cin >> n >> m;
  std::multiset<uint32_t> h;
  for (uint32_t i = 0; i != n; i++) {
    uint32_t tmp;
    std::cin >> tmp;
    h.insert(tmp);
  }
  for (uint32_t i = 0; i != m; i++) {
    uint32_t max;
    std::cin >> max;
    // No one gets any tickets
    if (h.empty()) {
      std::cout << "-1";
      continue;
    }

    // This gives TLE as std::multiset does not have random iterator access
    // Which increases the time complexity from O(log N) to O(N)
    // auto find = std::upper_bound(h.begin(), h.end(), max);
    auto find = h.upper_bound(max);

    if (find == h.begin()) {
      std::cout << "-1\n";
      continue;
    }

    std::cout << *std::prev(find) << "\n";
    h.erase(std::prev(find));
  }
}
