#include <iostream>
#include <vector>

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

constexpr int INF = 1 << 29;

int main() {
  std::string S, T;
  std::cin >> S >> T;

  std::vector<std::vector<int>> dp(S.length() + 1,
                                   std::vector<int>(T.length() + 1, INF));
  dp[0][0] = 0;  // 初期条件

  // O(|S||T|)
  for (int i = 0; i <= S.length(); ++i) {
    for (int j = 0; j <= T.length(); ++j) {
      // 削除操作
      if (i > 0) {
        chmin(dp[i][j], dp[i - 1][j] + 1);
      }
      // 挿入操作
      if (j > 0) {
        chmin(dp[i][j], dp[i][j - 1] + 1);
      }

      if (!(i > 0 && j > 0)) continue;

      // 変更操作
      if (S[i - 1] == T[j - 1]) {
        chmin(dp[i][j], dp[i - 1][j - 1]);
      } else {
        chmin(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  std::cout << dp[S.length()][T.length()] << std::endl;
}