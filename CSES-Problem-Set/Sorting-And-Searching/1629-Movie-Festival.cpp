#include <cstdint>
#include <iostream>
#include <set>

struct Movie {
  uint32_t a, b;
};

struct MovieComp {
  bool operator()(const Movie &l, const Movie &r) const { return l.b < r.b; }
};

int main() {
  uint32_t ans = 0;
  uint32_t currTime = 0;
  std::multiset<Movie, MovieComp> movies;
  uint32_t n;
  for (std::cin >> n; n != 0; n--) {
    uint32_t a, b;
    std::cin >> a >> b;
    movies.emplace(Movie{
        .a = a,
        .b = b,
    });
  }
  for (auto it = movies.begin(); it != movies.end(); it++) {
    if (it->a >= currTime) {
      currTime = it->b;
      ans++;
    }
  }
  std::cout << ans << "\n";
}
