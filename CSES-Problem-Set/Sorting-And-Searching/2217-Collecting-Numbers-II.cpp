#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  int32_t n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 2), b(n + 2);
  a[0] = 0;
  b[0] = 0;
  a[n + 1] = n + 1;
  b[n + 1] = n + 1;
  for (int32_t i = 1; i <= n; i++) {
    std::cin >> a[i];
    b[a[i]] = i;
  }
  int32_t ans = 1;
  int prev = -1;
  for (int32_t i = 1; i <= n; i++) {
    if (b[i] < prev) {
      ans++;
    }
    prev = b[i];
  }
  for (; m != 0; m--) {
    int32_t l, r;
    std::cin >> l >> r;

    if (b[a[l] - 1] < l && r <= b[a[l] - 1])
      ans++;
    if (b[a[l] - 1] > l && r >= b[a[l] - 1])
      ans--;
    if (b[a[l] + 1] < l && r <= b[a[l] + 1])
      ans--;
    if (b[a[l] + 1] > l && r >= b[a[l] + 1])
      ans++;
    b[a[l]] = r;

    if (b[a[r] - 1] < r && l <= b[a[r] - 1])
      ans++;
    if (b[a[r] - 1] > r && l >= b[a[r] - 1])
      ans--;
    if (b[a[r] + 1] < r && l <= b[a[r] + 1])
      ans--;
    if (b[a[r] + 1] > r && l >= b[a[r] + 1])
      ans++;
    b[a[r]] = l;

    // We don't use this as we need to account for the special case where x and
    // x + 1 are swapped where it causes double counting when using swap instead
    // of manually changing it std::swap(b[a[l]], b[a[r]]);
    std::swap(a[l], a[r]);

    std::cout << ans << "\n";
  }
}
