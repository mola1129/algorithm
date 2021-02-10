#include <iostream>
#include <vector>
constexpr int INF = 20000000;  // 十分大きな値に

int main() {
  // 入力を受け取る
  int N, K;
  std::cin >> N >> K;
  std::vector<int> a(N), b(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> b[i];
  }

  // 線形探索
  int min_value = INF;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      const int sum = a[i] + b[j];
      // 和が K 未満の場合は捨てる
      if (sum < K) continue;
      // 最小値を更新
      if (sum < min_value) {
        min_value = sum;
      }
    }
  }

  // 結果の出力
  std::cout << "ペア和の最小値: " << min_value << std::endl;
}