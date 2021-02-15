#include <iostream>
#include <vector>

/*
 * @param n 項数
 * @param memo メモ化用配列
 * @return n 項目の tribonacci 数
 */
long long get_tribonacci_number(const int n, std::vector<long long>& memo) {
  if (memo[n] != -1) {
    return memo[n];
  }
  return memo[n] = get_tribonacci_number(n - 1, memo) +
                   get_tribonacci_number(n - 2, memo) +
                   get_tribonacci_number(n - 3, memo);
}

/*
 * @param n 項数
 * @return n 項目の tribonacci 数
 */
long long tribonacci(const int n) {
  std::vector<long long> memo(n, -1);
  memo[0] = 0, memo[1] = 0, memo[2] = 1;
  return get_tribonacci_number(n - 1, memo);
}

int main() {
  int n;
  std::cin >> n;
  std::cout << tribonacci(n) << std::endl;
}