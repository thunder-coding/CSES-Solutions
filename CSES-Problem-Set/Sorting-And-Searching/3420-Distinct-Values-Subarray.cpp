#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
int main() {
  std::ios::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::cin >> n;
  std::set<int> s;
  int l = 1, r = 1;
  uint64_t ans = 0;
  std::vector<int> a(n);
  for (int i = 0; i != n; i++)
    std::cin >> a[i];

  for (l = 1; l <= n; l++) {
    while (r <= n && s.find(a[r - 1]) == s.end()) {
      s.emplace(a[r - 1]);
      r++;
    }
    ans += (r - l);
    s.erase(a[l - 1]);
  }
  std::cout << ans << "\n";
}
