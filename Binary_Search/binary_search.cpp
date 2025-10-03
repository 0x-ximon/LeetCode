#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int p = 0, q = nums.size() - 1;

        while (p <= q) {
            int m = (p + q) / 2;
            if (nums[m] == target) return m;
            if (nums[m] < target) p = m + 1;
            if (nums[m] > target) q = m - 1;
        }

        return -1;
    }
};
