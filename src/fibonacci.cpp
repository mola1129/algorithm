#include <iostream>
#include <vector>

// 指数オーダー
long long fibonacci_1(int n) {
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
long long fibonacci_2(int n) {
  std::vector<long long> a(n + 1);
  a[0] = 0, a[1] = 1;
  for (int i = 2; i < n + 1; ++i) {
    a[i] = a[i - 1] + a[i - 2];
  }
  return a[n];
}

// メモ化 O(n)
long long fibonacci_3(std::vector<long long>& memo, int n) {
  if (memo[n] != -1) {
    return memo[n];
  }
  return memo[n] = fibonacci_3(memo, n - 1) + fibonacci_3(memo, n - 2);
}

int fibonacci_memo(int n) {
  std::vector<long long> memo(n + 1, -1);
  memo[0] = 0, memo[1] = 1;
  return fibonacci_3(memo, n);
}

int main() {
  int n;
  std::cin >> n;
  std::cout << fibonacci_memo(n) << std::endl;
}