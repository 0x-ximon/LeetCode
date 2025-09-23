#include <unordered_map>
using namespace std;

class Solution {
 public:
  int fib(int n) {
    unordered_map<int, int> m;
    return compute(m, n);
  }

  int compute(unordered_map<int, int>& m, int n) {
    if (n == 0 || n == 1) return n;
    if (m.find(n) != m.end()) return m[n];

    m[n] = compute(m, n - 1) + compute(m, n - 2);
    return m[n];
  }
};
