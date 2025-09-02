#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> j;
    for (auto c : jewels) j.insert(c);

    int k = 0;
    for (auto c : stones)
      if (j.find(c) != j.end()) k++;

    return k;
  }
};
