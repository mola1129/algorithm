#include <iostream>
#include <vector>

// func(i, w, a)の答えをメモ化する配列
std::vector<std::vector<int>> memo;

// 0: false 1: true
int dp(int i, int w, const std::vector<int> &a) {
  // ベースケース
  if (i == 0) {
    if (w == 0)
      return true;
    else
      return false;
  }

  // メモをチェック (すでに計算済みならば答えをリターンする)
  if (memo[i][w] != -1) return memo[i][w];

  // a[i-1] を選ばない場合
  if (dp(i - 1, w, a)) return memo[i][w] = 1;

  // a[i-1] を選ぶ場合
  if (dp(i - 1, w - a[i - 1], a)) return memo[i][w] = 1;

  // どちらも false の場合は false
  return memo[i][w] = 0;
}

int main() {
  // 入力
  int N, W;
  std::cin >> N >> W;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) std::cin >> a[i];

  // 再帰的に解く
  memo.assign(N + 1, std::vector<int>(W + 1, -1));
  if (dp(N, W, a))
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;
}