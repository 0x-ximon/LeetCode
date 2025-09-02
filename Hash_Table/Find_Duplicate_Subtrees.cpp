#include <string>
#include <unordered_map>
#include <vector>
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
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> subtrees;
    vector<TreeNode*> result;

    dfs(root, subtrees, result);
    return result;
  }

 private:
  string dfs(TreeNode* node, unordered_map<string, int>& subtrees,
             vector<TreeNode*>& result) {
    if (!node) return "N";

    string s = to_string(node->val) + " " + dfs(node->left, subtrees, result) +
               " " + dfs(node->right, subtrees, result);

    subtrees[s]++;

    if (subtrees[s] == 2) result.push_back(node);
    return s;
  }
};
