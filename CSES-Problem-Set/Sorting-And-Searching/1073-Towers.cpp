#include <iostream>
#include <set>
int main() {
  std::multiset<int> s;
  int n;
  for (std::cin >> n; n != 0; n--) {
    int t;
    std::cin >> t;
    auto it = s.upper_bound(t);
    if (it != s.end()) {
      s.erase(it);
    }
    s.emplace(t);
  }
  std::cout << s.size() << "\n";
}
