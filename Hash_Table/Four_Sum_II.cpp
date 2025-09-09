#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int> num1, vector<int> num2, vector<int> num3,
                   vector<int> num4) {
    unordered_map<int, int> occured = {};
    for (int i : num1) {
      for (int j : num2) {
        occured[i + j]++;
      }
    }

    int result = 0;
    for (int k : num3) {
      for (int l : num4) {
        int diff = 0 - (k + l);
        result += occured[diff];
      }
    }

    return result;
  }
};
