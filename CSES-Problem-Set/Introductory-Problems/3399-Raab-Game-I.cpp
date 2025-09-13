#include <algorithm>
#include <iostream>
int main() {
  int t;
  for (std::cin >> t; t != 0; t--) {
    int n, a, b;
    std::cin >> n >> a >> b;
    if (a + b > n || (a != 0 && b == 0) || (a == 0 && b != 0)) {
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
    // Player A
    for (int i = 1; i <= n - (a + b); i++) {
      std::cout << i << " ";
    }
    for (int i = n - a + 1; i <= n; i++) {
      std::cout << i << " ";
    }
    for (int i = n - (a + b) + 1; i <= n - (a + b) + b; i++) {
      std::cout << i << " ";
    }
    //
    std::cout << "\n";
    // Player B
    for (int i = 0; i != n; i++) {
      std::cout << (i + 1) << " ";
    }
    std::cout << "\n";
  }
}
