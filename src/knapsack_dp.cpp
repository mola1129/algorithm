#include <iostream>
#include <vector>

/*
 * 最大値に更新する
 * @param a 最大値 (更新対象)
 * @param b 比較対象
 */
template <class T>
void chmax(T &a, const T b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  int N;
  long long W;
  std::cin >> N >> W;
  std::vector<long long> value(N), weight(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> value[i] >> weight[i];
  }

  // dp[i][w]: i 番目までの荷物を選択した際の w 以下の最大合計価値
  std::vector<std::vector<long long>> dp(N + 1,
                                         std::vector<long long>(W + 1, 0));

  // O(NW)
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= W; ++j) {
      chmax(dp[i + 1][j], dp[i][j]);  // 品物 i を選ばない

      if (j - weight[i] >= 0) {
        chmax(dp[i + 1][j], dp[i][j - weight[i]] + value[i]);  // 品物 i を選ぶ
      };
    }
  }

  std::cout << dp[N][W] << std::endl;
}