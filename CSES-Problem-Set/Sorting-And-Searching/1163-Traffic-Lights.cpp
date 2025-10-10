#include <iostream>
#include <iterator>
#include <set>
int main() {
  std::ios::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int x, n;
  std::cin >> x >> n;
  std::multiset<int> gaps = {x};
  std::set<int> lights = {0, x};
  for (; n != 0; n--) {
    int t;
    std::cin >> t;
    auto ub = lights.upper_bound(t);
    auto lb = std::prev(ub);
    int h = *ub;
    int l = *lb;
    gaps.erase(gaps.find(h - l));
    lights.insert(t);
    gaps.emplace(h - t);
    gaps.emplace(t - l);
    std::cout << *std::prev(gaps.end()) << "\n";
  }
}
