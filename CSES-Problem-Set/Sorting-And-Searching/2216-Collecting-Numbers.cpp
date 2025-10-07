#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  uint32_t n;
  std::cin >> n;
  uint32_t ans = 1;
  std::vector<int> a(n), b(n);
  for (int i = 0; i != n; i++) {
    std::cin >> a[i];
    b[a[i] - 1] = i;
  }
  int prev = -1;
  for (int i = 0; i != n; i++) {
    if (b[i] < prev) {
      ans++;
    }
    prev = b[i];
  }
  std::cout << ans << "\n";
}
