#include <iostream>
#include <string>
int main() {
  int n, m;
  std::cin >> n >> m;
  std::string line;
  line.reserve(m);
  for (int i = 0; i != n; i++) {
    std::cin >> line;
    for (int j = 0; j != m; j++) {
      char ch;
      // This ensures that the character at each position is always changed
      if (line[j] <= 'B') {
        ch = 'C';
      } else {
        ch = 'A';
      }
      // This ensures alternating pattern
      // All immediately adjacent cells will differ in their (i + j) values to
      // be exactly one. So they will never be the same
      if ((i + j) % 2 == 0) {
        ch++;
      }
      std::cout << ch;
    }
    std::cout << "\n";
  }
}
