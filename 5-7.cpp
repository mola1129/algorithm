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
  std::string s, t;
  std::cin >> s;
  std::cin >> t;

  std::vector<std::vector<int>> dp(s.length() + 1,
                                   std::vector<int>(t.length() + 1, 0));

  for (int i = 1; i <= s.length(); ++i) {
    for (int j = 1; j <= t.length(); ++j) {
      chmax(dp[i][j], dp[i - 1][j]);
      chmax(dp[i][j], dp[i][j - 1]);

      if (s[i - 1] == t[j - 1]) {
        chmax(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  // LCSを形成
  int lcs_length = dp[s.length()][t.length()];
  std::string answer(lcs_length, 'x');
  int i = s.length(), j = t.length();
  while (lcs_length > 0) {
    if (s[i - 1] == t[j - 1]) {
      answer[lcs_length - 1] = s[i - 1];
      --i;
      --j;
      --lcs_length;
    } else if (dp[i][j] == dp[i - 1][j]) {
      --i;
    } else {
      --j;
    }
  }

  std::cout << answer << std::endl;
}