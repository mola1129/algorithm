#include <iostream>
#include <vector>

template <class T>
void chmax(T& a, const T b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  int N;
  std::cin >> N;

  // happiness[i][j]: i 日目に j の選択肢を選んだ際の幸福度
  std::vector<std::vector<int>> happiness(N + 1, std::vector<int>(3, 0));
  for (int i = 1; i <= N; ++i) {
    std::cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
  }

  // dp[i][j]: i 日目に j の選択肢を選んだ際の幸福度の総和の最大
  // 初期条件: dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
  std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(3, 0));

  // O(N)
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < 3; ++j) {
      // k: 前日に選んだ選択肢
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;  // 2日連続は不可
        chmax(dp[i][j], dp[i - 1][k] + happiness[i][j]);
      }
    }
  }

  long long result = 0;
  for (int j = 0; j < 3; ++j) {
    chmax(result, dp[N][j]);
  }

  std::cout << result << std::endl;
}