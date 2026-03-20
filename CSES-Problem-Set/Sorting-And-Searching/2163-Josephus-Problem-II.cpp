#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

[[nodiscard]] inline uint64_t first_lsb0(uint64_t x) {
  uint64_t ans = 0;
  for (int i = 0; i < 64; i++) {
    if (((static_cast<uint64_t>(1) << i) & x) == 0) return i + 1;
  }
  return 65;
}

[[nodiscard]] inline uint64_t first_lsb1(uint64_t x) {
  for (int i = 0; i < 64; i++) {
    if ((static_cast<uint64_t>(1) << i) & x) return i + 1;
  }
  return 65;
}

[[nodiscard]] inline uint64_t BIT_get(const std::vector<uint64_t>& precomp, uint64_t index) {
  uint64_t ans = 0;
  while (true) {
    ans += precomp[index];
    if (index == 0) [[unlikely]] break;
    uint64_t lsb0 = first_lsb0(index);
    if (lsb0 > 1) {
      index ^= ((static_cast<uint64_t>(1) << (lsb0 - 1)) - 1);
    }
    if (index == 0) break;
    index--;
  }
  return ans;
}

inline void BIT_update(std::vector<uint64_t>& precomp, uint64_t index) {
  while (index < precomp.size()) {
    precomp[index]--;
    index |= (index + 1);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  uint64_t n;
  uint64_t k;
  std::cin >> n >> k;

  // This is a Fenwick Tree pre-computation/BIT(Binary Indexed Tree)
  std::vector<uint64_t> precomp(n);

  // Populate the initial table
  for (uint64_t i = 0; i != n; i++) {
    precomp[i] = 1;
    for (uint64_t index = first_lsb0(i) - 1; index != 0; index--) {
      precomp[i] += precomp[i & ~(1 << index)];
    }
  }
  
  uint64_t curr = k % n;
  // Time complexity analysis
  // O(n(logn)^2)
  //
  // n (log n) (log n)
  //
  // n -> number of elements
  // log n -> binary search
  // log n -> Fenwick tree update/get
  for (uint64_t i = 0; i != n; i++) {
    std::cout << curr + 1 << " ";
    if (i == (n - 1)) [[unlikely]] { break; }
    BIT_update(precomp, curr);
    // XXX:
    // We should be able to optimize this slightly to just curr_count, and just decrement that.
    // I don't think the compiler will be able to figure this shit out by itself?
    uint64_t l = BIT_get(precomp, curr);
    uint64_t r = n - i - 1 - l;
    uint64_t advance = k % (l + r) + 1;
    // Now do binary search to figure out where to fucking land on
    uint64_t left, right, search;
    if (r == 0) {
      left = 0;
      right = curr - 1;
      search = advance;
    } else if (advance <= r) {
      left = curr + 1;
      right = n - 1;
      search = l + advance;
    } else {
      left = 0;
      right = curr - 1;
      search = advance - r;
    }
    while (left < right) {
      uint64_t mid = left + (right - left) / 2;
      if (search <= BIT_get(precomp, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    // Now left and right point to the same shit and is what we are looking for.
    curr = right;
  }

  return EXIT_SUCCESS;
}
