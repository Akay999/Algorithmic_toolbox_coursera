#include <iostream>

int gcd_naive(int a, int b) {
  if ( a == 1 || b == 1)
    return 1;
  
  int best = 1;
  int min_input = std::min(a, b);
  for (int i = 2; i <= min_input; i++) {
    if(a % i == 0 && b % i == 0) {
      best = i;
    }
  }
  return best;
}

int gcd_fast(long long a, long long b) {
  if(b == 0)
    return a;
  
  return gcd_fast(b, a % b);
  
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}