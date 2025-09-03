#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> indexes;
    int result = 0;
    int start = 0;

    for (int end = 0; end < s.length(); end++) {
      if (indexes.find(s[end]) != indexes.end() && indexes[s[end]] >= start) {
        start = indexes[s[end]] + 1;
      }

      result = max(result, end - start + 1);
      indexes[s[end]] = end;
    }

    return result;
  }
};
