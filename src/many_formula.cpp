#include <iostream>

int main() {
  std::string S;
  std::cin >> S;
  const int N = S.size();

  const int MAX_BIT = (1 << (N - 1));
  long long answer = 0;
  for (int bit = 0; bit < MAX_BIT; ++bit) {
    // tmp: 各項の値
    long long tmp = S[0] - '0';  // 数値への変換
    for (int i = 0; i < N - 1; ++i) {
      if (bit & (1 << i)) {
        answer += tmp;  // + が来たら加算
        tmp = 0;
      }
      tmp *= 10;
      tmp += S[i + 1] - '0';  // 数値への変換
    }
    answer += tmp;  // 残った最終項を加算
  }
  std::cout << answer << std::endl;
}