#include <iostream>

/*
 * @param N 753数の上限値
 * @param cur: 現在の値
 * @param exists 7, 5, 3 の存在フラグ
 * @return cur <= N を満たす 753 数の個数
 */
long long get_753_number_count(const long long N, long long cur = 0,
                               const int exists = 0) {
  // ベースケース
  if (cur > N) {
    return 0;
  }

  // 753数のチェック
  int result = 0;
  if (exists == 0b111) {
    result = 1;
  }

  // 3通りに分岐する
  return result + get_753_number_count(N, 10 * cur + 7, exists | 0b100) +
         get_753_number_count(N, 10 * cur + 5, exists | 0b010) +
         get_753_number_count(N, 10 * cur + 3, exists | 0b001);
}

int main() {
  int K;
  std::cin >> K;
  std::cout << get_753_number_count(K) << std::endl;
}