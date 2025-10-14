#include <array>
#include <cassert>
#include <iostream>
#include <string>
int ans = 0;

void solve(const std::array<std::array<bool, 8>, 8> &occupied, int row) {
  // for (int i = 0; i != 8; i++) {
  //   for (int j = 0; j != 8; j++) {
  //     std::cerr << (occupied[i][j] ? '*' : '.');
  //   }
  //   std::cerr << "\n";
  // }
  std::cerr << "\n\n";
  for (int i = 0; i != 8; i++) {
    if (!occupied[row][i]) {
      if (row == 7) {
        // std::cerr << "Incremented ans\n";
        ans++;
        continue;
      }
      auto copy = occupied;
      for (int j = row + 1; j != 8; j++) {
        copy[j][i] = true;
      }
      for (int j = row + 1, k = i + 1; j < 8 && k < 8; j++, k++) {
        copy[j][k] = true;
      }
      for (int j = row + 1, k = i - 1; j < 8 && k >= 0; j++, k--) {
        copy[j][k] = true;
      }
      solve(copy, row + 1);
    }
  }
}

int main() {
  std::array<std::array<bool, 8>, 8> occupied;
  for (int i = 0; i != 8; i++) {
    std::string line;
    std::cin >> line;
    for (int j = 0; j != 8; j++) {
      if (line[j] == '.') {
        occupied[i][j] = false;
      } else if (line[j] == '*') {
        occupied[i][j] = true;
      } else {
        assert(false);
      }
    }
  }
  solve(occupied, 0);
  std::cout << ans << "\n";
}
