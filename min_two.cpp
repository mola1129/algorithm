#include <iostream>
#include <vector>
constexpr int INF = 20000000;

int main() {
  // 入力を受け取る
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  // 線形探索
  int worst_value = INF;
  int second_value = INF;
  for (int i = 0; i < N; ++i) {
    if (a[i] < worst_value) {
      second_value = worst_value;
      worst_value = a[i];
    } else if (a[i] < second_value) {
      second_value = a[i];
    }

    // 結果の出力
    std::cout << "二番目に小さい数: " << second_value << std::endl;
  }
}