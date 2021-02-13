#include <iostream>
#include <vector>

// 指数オーダー
int fibonacci_1(int n) {
  // ベースケース
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fibonacci_1(n - 1) + fibonacci_1(n - 2);
}

// O(n)
int fibonacci_2(int n) {
  std::vector<int> a(n + 1);
  a[0] = 0, a[1] = 1;
  for (int i = 2; i < n + 1; ++i) {
    a[i] = a[i - 1] + a[i - 2];
  }
  return a[n];
}

int main() {
  int n;
  std::cin >> n;
  std::cout << fibonacci_2(n) << std::endl;
}