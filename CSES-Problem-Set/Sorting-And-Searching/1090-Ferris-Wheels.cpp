#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
int main() {
  uint32_t n, x;
  std::vector<uint32_t> p;
  std::cin >> n >> x;
  p.resize(n);
  for (uint32_t i = 0;i != n; i++) {
    std::cin >> p[i];
  }
  std::sort(p.begin(), p.end());
  uint32_t ans = 0;
  uint32_t l = 0, r = n - 1;
  for (; l < r;) {
    if (p[l] + p[r] > x) {
      ans++;
      r--;
    } else {
      ans++;
      l++;
      r--;
    }
  }
  if (l == r) {
    ans++;
  }
  std::cout << ans << "\n";
}
