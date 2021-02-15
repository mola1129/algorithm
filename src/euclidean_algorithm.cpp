#include <iostream>

// O(log n)
int gcd(int n, int m) {
  // euclidean algorithm
  if (m == 0) {
    return n;
  }
  return gcd(m, n % m);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::cout << gcd(n, m) << std::endl;
}