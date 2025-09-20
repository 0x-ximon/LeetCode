#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) { reverse(0, s.size() - 1, s); }
  void reverse(int i, int j, vector<char>& s) {
    if (i >= j) return;

    swap(s[i], s[j]);
    reverse(++i, --j, s);
  };
};
