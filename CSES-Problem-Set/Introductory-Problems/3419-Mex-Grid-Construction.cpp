#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << "0\n";
    return EXIT_SUCCESS;
  }
  std::vector<std::vector<int>> ans;
  ans.resize(n);
  for (int i = 0; i != n; i++) {
    ans[i].resize(n);
  }
  // Populate the pre-computation
  ans[0][0] = 0;
  ans[0][1] = 1;
  ans[1][0] = 1;
  ans[1][1] = 0;
  for (int i = 0; i < std::log2(n); i++) {
    for (int j = (1 << i); j != (1 << (i + 1)); j++) {
      for (int k = (1 << i); k != (1 << (i + 1)); k++) {
        if (j < n && k < n)
          ans[j][k] = ans[j - (1 << i)][k - (1 << i)];
        if (j < n && k - (1 << i) < n)
          ans[j][k - (1 << i)] = ans[j - (1 << i)][k - (1 << i)] + (1 << i);
        if (j - (1 << i) < n && k < n)
          ans[j - (1 << i)][k] = ans[j - (1 << i)][k - (1 << i)] + (1 << i);
      }
    }
  }
  for (int i = 0; i != n; i++) {
    for (int j = 0; j != n; j++) {
      std::cout << ans[i][j] << " ";
    }
    std::cout << "\n";
  }
}
