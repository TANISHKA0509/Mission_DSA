/
#include <cstddef>

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root) ? root : nullptr;
    }

private:
    bool containsOne(TreeNode* node) {
        if (!node) return false;

        bool leftContainsOne = containsOne(node->left);
        bool rightContainsOne = containsOne(node->right);

        if (!leftContainsOne) node->left = nullptr;
        if (!rightContainsOne) node->right = nullptr;

        return node->val == 1 || leftContainsOne || rightContainsOne;
    }
};
