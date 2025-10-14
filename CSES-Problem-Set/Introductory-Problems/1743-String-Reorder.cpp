#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>

std::array<uint32_t, 26> chars;
std::string line, ans;
char prev = 26;

inline uint32_t max_arr() {
  uint32_t max = 0;
  for (uint32_t i = 0; i != 26; i++) {
    max = std::max(max, chars[i]);
  }
  return max;
}

inline bool solve() {
  // First check if a solution is possible in this configuration:
  // Now select the character to add
  for (uint32_t i = 0; i != line.size();) {
    bool found = false;
    for (uint32_t j = 0; j != 26; j++) {
      if (chars[j] != 0 && j != prev) {
        chars[j]--;
        if (max_arr() <= ((line.size() - i) / 2)) {
          found = true;
          ans[i] = j + 'A';
          i++;
          prev = j;
          break;
        } else {
          chars[j]++;
        }
      }
    }
    if (!found)
      return false;
  }
  return true;
}

int main() {
  for (uint32_t i = 0; i != 26; i++) {
    chars[i] = 0;
  }
  line.reserve(1000000);
  std::cin >> line;
  for (uint32_t i = 0; i != line.size(); i++) {
    chars[line[i] - 'A']++;
  }
  ans.resize(line.size(), '\0');
  if (!solve()) {
    std::cout << "-1\n";
  } else {
    std::cout << ans << "\n";
  }
}
