#include <iostream>
#include <vector>

int how_many_times(int n) {
  if (n % 2 == 1) {
    return 0;
  }
  return 1 + how_many_times(n / 2);
}

constexpr int INF = 20000000;

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  int answer = INF;
  for (auto count : A) {
    answer = std::min(answer, how_many_times(count));
  }

  std::cout << "操作の回数: " << answer << std::endl;
}