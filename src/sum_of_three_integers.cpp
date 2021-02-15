#include <iostream>
#include <vector>

int main() {
  int K, N;
  std::cin >> K >> N;

  const int MAX = std::min(K, N);
  int answer = 0;
  for (int x = 0; x <= MAX; ++x) {
    for (int y = 0; y <= MAX; ++y) {
      int z = N - x - y;
      if (0 <= z && z <= K) {
        ++answer;
      }
    }
  }

  std::cout << answer << std::endl;
}