#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts = {};
    vector<int> result = {};
    for (auto num : nums) {
      counts[num]++;
    }

    vector<pair<int, int>> buffer(counts.size());
    for (auto [k, v] : counts) {
      buffer.push_back({k, v});
    }

    sort(buffer.begin(), buffer.end(),
         [](const pair<int, int> a, const pair<int, int> b) {
           return a.second > b.second;
         });

    auto it = buffer.begin();
    for (int i = 0; i < k; i++) {
      result.push_back(it->first);
      it++;
    }

    return result;
  }
};
