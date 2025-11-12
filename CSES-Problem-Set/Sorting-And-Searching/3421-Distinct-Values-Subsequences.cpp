#include <cstdint>
#include <iostream>
#include <map>

constexpr uint64_t MOD = 1'000'000'007;

int main() {
  std::ios::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::cin >> n;
  std::map<int, int> m;
  for (int i = 0; i != n; i++) {
    int tmp;
    std::cin >> tmp;
    m[tmp]++;
  }
  uint64_t res = 1;
  for (const auto &[x, freq] : m) {
    res *= (freq + 1);
    res %= MOD;
  }
  std::cout << res - 1 << "\n";
}
