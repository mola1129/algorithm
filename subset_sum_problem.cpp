#include <iostream>
#include <vector>

int main() {
  // 入力受け取り
  int N, W;
  std::cin >> N >> W;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  // bit は 2^N 通りの部分集合全体を動きます
  bool exists = false;
  // べき乗は std::pow(x, y) でも OK
  for (int bit = 0; bit < (1 << N); ++bit) {
    int sum = 0;  // 部分集合に含まれる要素の和
    for (int i = 0; i < N; ++i) {
      // i 番目の要素 a[i] が部分集合に含まれているかどうか
      if (bit & (1 << i)) {
        sum += a[i];
      }
    }

    // sum が W に一致するかどうか
    if (sum == W) {
      exists = true;
      break;
    }
  }

  if (exists) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}
