#include <iostream>
#include <vector>

int main() {
  // 入力を受け取る
  int N, v;
  std::cin >> N >> v;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  // 線形探索
  int found_id = -1;  // 初期値は -1 などありえない値にする
  for (int i = 0; i < N; ++i) {
    if (a[i] == v) {
      found_id = i;  // 見つかったら添え字を記録
      break;         // ループを抜ける
    }
  }

  // 結果の出力 (-1 のときは見つからなかったことを表す)
  if (found_id == -1) {
    std::cout << "Not Existed" << std::endl;
  } else {
    std::cout << found_id << std::endl;
  }
}