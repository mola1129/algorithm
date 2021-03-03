#include <iostream>
#include <vector>

constexpr int INF = 1000000000;

/*
 * 最小値に更新する
 * @param a 最小値 (更新対象)
 * @param b 比較対象
 */
template <class T>
void chmin(T& a, const T b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  int N, W, K;
  std::cin >> N >> K >> W;

  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  // dp[i][w]: 選択した数字の個数
  // 一般的に bool 値を求める dp は無駄であることが多く，
  // 保持する値自身に意味を持たせることで，同じ計算量で多くの情報を得ることが可能
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, INF));
  dp[0][0] = 0;  // 初期条件

  for (int i = 1; i <= N; ++i) {
    for (int w = 0; w <= W; ++w) {
      chmin(dp[i][w], dp[i - 1][w]);  // 選ばない

      if (w - a[i - 1] >= 0) {
        chmin(dp[i][w], dp[i - 1][w - a[i - 1]] + 1);  // 選ぶ
      }
    }
  }

  if (dp[N][W] <= K) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}