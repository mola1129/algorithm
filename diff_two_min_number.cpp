#include <iostream>
#include <vector>
const int INF = 20000000;

int main() {
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  int max_value = -INF;
  int min_value = INF;
  for (int i = 0; i < N; ++i) {
    if (a[i] > max_value) {
      max_value = a[i];
    }

    if (a[i] < min_value) {
      min_value = a[i];
    }
  }

  const int diff = max_value - min_value;
  std::cout << "2つの数の差の最大値: " << diff << std::endl;
}