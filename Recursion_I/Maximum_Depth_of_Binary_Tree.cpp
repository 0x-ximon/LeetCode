#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int maxDepth(TreeNode* root) { return traverse(root, 1); }
  int traverse(TreeNode* node, int depth) {
    if (!node) return depth - 1;

    int largestSubDepth =
        max(traverse(node->left, depth + 1), traverse(node->right, depth + 1));

    return max(largestSubDepth, depth);
  }
};
