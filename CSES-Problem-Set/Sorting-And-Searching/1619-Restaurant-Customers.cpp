#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
struct CustomerInfo {
  uint32_t a, b;
};

struct aComp{
bool operator()(const CustomerInfo& l, const CustomerInfo& r) const {
  return (l.a < r.a) || (l.a == r.a && l.b < r.b);
}
};

struct bComp{
bool operator()(const CustomerInfo& l, const CustomerInfo& r) const {
  return (l.b < r.b);
}
};

int main() {
  uint32_t n;
  uint32_t ans = 0, curr = 0;
  std::set<CustomerInfo, aComp> customers;
  std::set<CustomerInfo, bComp> leaveQueue;
  for(std::cin >> n; n != 0; n--) {
    uint32_t a, b;
    std::cin >> a >> b;
    customers.emplace(CustomerInfo{
      .a = a,
      .b = b
    });
  }
  while (!customers.empty() && curr + customers.size() > ans) {
    leaveQueue.emplace(*customers.begin());
    while (!leaveQueue.empty() && leaveQueue.begin()->b < customers.begin()->a) {
      leaveQueue.erase(leaveQueue.begin());
    }
    customers.erase(customers.begin());
    curr = leaveQueue.size();
    ans = std::max(curr, ans);
  }
  std::cout << ans << "\n";
}
