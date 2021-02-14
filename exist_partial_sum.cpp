#include <iostream>
#include <vector>

bool exist_partial_sum(const std::vector<int>& a, int n, int w) {
  if (n == 0) {
    if (w == 0) {
      return true;
    }
    return false;
  }
  return exist_partial_sum(a, n - 1, w - a[n - 1]) ||
         exist_partial_sum(a, n - 1, w);
}

int main() {
  int n, w;
  std::cin >> n >> w;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  if (exist_partial_sum(a, n, w)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}