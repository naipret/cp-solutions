#include <iostream>

// using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int wid{}, que{};
  std::cin >> wid >> que;
  bool arr[wid + 1][wid + 1] = {false};
  char buffer{};
  for (int r{1}; r <= wid; ++r) {
    for (int c{1}; c <= wid; ++c) {
      std::cin >> buffer;
      if (buffer == '*') {
        arr[r][c] = true;
      }
    }
  }

  int pre2D[wid + 1][wid + 1];
  for (auto &r : pre2D) {
    r[0] = 0;
  }
  for (int &c : pre2D[0]) {
    c = 0;
  }
  for (int r{1}; r <= wid; ++r) {
    for (int c{1}; c <= wid; ++c) {
      pre2D[r][c] =
          pre2D[r - 1][c] + pre2D[r][c - 1] - pre2D[r - 1][c - 1] + arr[r][c];
    }
  }

  int r1{}, c1{}, r2{}, c2{};
  while (que--) {
    std::cin >> r1 >> c1 >> r2 >> c2;
    int ans{pre2D[r2][c2] - pre2D[r1 - 1][c2] - pre2D[r2][c1 - 1] +
            pre2D[r1 - 1][c1 - 1]};
    std::cout << ans << '\n';
  }

  return 0;
}
