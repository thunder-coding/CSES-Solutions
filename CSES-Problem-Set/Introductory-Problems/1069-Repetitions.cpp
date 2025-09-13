#include <cstdlib>
#include <iostream>
int main() {
  int prevch = -1;
  char ch;
  int count = 0;
  int maxcount = 0;
  while(true) {
    std::cin >> ch;
    if (!std::cin.good() || (ch != 'A' && ch != 'C' && ch != 'G' && ch != 'T')) {
      std::cout << maxcount << "\n";
      return EXIT_SUCCESS;
    }
    if (ch == prevch) {
      count++;
    } else {
      prevch = ch;
      count = 1;
    }
    maxcount = std::max(maxcount, count);
  }
}
