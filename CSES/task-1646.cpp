#include <iostream>
// #include <numeric>  // std::partial_sum

// using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int col{}, que{};
  std::cin >> col >> que;
  int arr[col + 1];
  for (int c{1}; c <= col; ++c) {
    std::cin >> arr[c];
  }

  long long pre[col + 1];
  pre[0] = 0LL;
  for (int c{1}; c <= col; ++c) {
    pre[c] = pre[c - 1] + arr[c];
  }
  // std::partial_sum(arr, arr + (col + 1), pre);

  int l{}, r{};
  while (que--) {
    std::cin >> l >> r;
    long long ans{pre[r] - pre[l - 1]};
    std::cout << ans << '\n';
  }

  return 0;
}
