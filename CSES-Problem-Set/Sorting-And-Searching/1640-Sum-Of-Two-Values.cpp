#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
struct Element {
  uint32_t index, val;
};

struct ElementComp {
  bool operator()(const Element &l, const Element &r) const {
    return l.val < r.val;
  }
};

int main() {
  uint32_t n, x;
  std::multiset<Element, ElementComp> a;
  std::cin >> n >> x;
  for (uint32_t i = 0; i != n; i++) {
    uint32_t tmp;
    std::cin >> tmp;
    a.emplace(Element{
        .index = i + 1,
        .val = tmp,
    });
  }
  for (auto l = a.begin(), r = std::prev(a.end()); l != r;) {
    if (l->val + r->val > x) {
      r = std::prev(r);
    } else if (l->val + r->val < x) {
      l = std::next(l);
    } else {
      std::cout << l->index << " " << r->index << "\n";
      return EXIT_SUCCESS;
    }
  }
  std::cout << "IMPOSSIBLE\n";
}
