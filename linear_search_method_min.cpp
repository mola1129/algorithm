#include <iostream>
#include <vector>
constexpr int INF = 20000000;  // 十分大きな値に

int main() {
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  // 線形探索
  int min_value = INF;
  for (int i = 0; i < N; ++i) {
    if (a[i] < min_value) {
      min_value = a[i];
    }
  }

  // 結果の出力
  std::cout << "最小値: " << min_value << std::endl;
}