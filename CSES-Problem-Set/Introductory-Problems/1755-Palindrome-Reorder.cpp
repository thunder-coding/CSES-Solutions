#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
int main() {
  std::array<uint32_t, 26> count;
  for (size_t i = 0; i != count.size(); i++) {
    count[i] = 0;
  }
  std::string str;
  std::cin >> str;
  for (const auto &ch : str) {
    count[ch - 'A']++;
  }
  std::string ans(static_cast<size_t>(str.size()), ' ');
  if (str.size() % 2 == 0) {
    size_t k = 0;
    for (size_t i = 0; i != count.size(); i++) {
      if (count[i] % 2 == 0) {
        for (size_t j = 0; j != count[i] / 2; j++, k++) {
          ans[k] = 'A' + i;
          ans[ans.size() - 1 - k] = 'A' + i;
        }
      } else {
        std::cout << "NO SOLUTION\n";
        return EXIT_SUCCESS;
      }
    }
  } else {
    bool found_odd = false;
    size_t k = 0;
    for (size_t i = 0; i != count.size(); i++) {
      if (count[i] % 2 == 1) {
        if (found_odd) {
          std::cout << "NO SOLUTION\n";
          return EXIT_SUCCESS;
        } else {
          ans[ans.size() / 2] = 'A' + i;
          for (size_t j = 0; j != (count[i] + 1) / 2; j++) {
            ans[ans.size() / 2 - j] = 'A' + i;
            ans[ans.size() / 2 + j] = 'A' + i;
          }
          found_odd = true;
        }
      } else {
        for (size_t j = 0; j != count[i] / 2; j++, k++) {
          ans[k] = 'A' + i;
          ans[ans.size() - 1 - k] = 'A' + i;
        }
      }
    }
  }
  std::cout << ans << "\n";
}
