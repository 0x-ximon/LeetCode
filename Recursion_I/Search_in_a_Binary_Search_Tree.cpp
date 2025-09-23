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
  TreeNode* searchBST(TreeNode* root, int val) { return search(root, val); }
  TreeNode* search(TreeNode* node, int val) {
    if (!node) return nullptr;
    if (node->val == val) return node;

    TreeNode* result = nullptr;

    result = search(node->left, val);
    if (result) return result;

    result = search(node->right, val);
    if (result) return result;

    return result;
  }
};
