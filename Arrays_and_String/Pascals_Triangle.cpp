#include <vector>

class Solution {
   public:
    // Algorithm Analysis
    //      Time Complexity:     Ο(n*2) Ω(1)
    //      Space Complexity:    Ο(n*2) Ω(1)
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result(numRows);

        for (int i = 0; i < numRows; i++) {
            result[i].assign(i + 1, 1);

            for (int j = 1; j < i; j++) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }

        return result;
    }
};
