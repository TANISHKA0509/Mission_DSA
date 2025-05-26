class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool helper(TreeNode* node, long min_val, long max_val) {
        if (!node) return true;
        if (node->val <= min_val || node->val >= max_val) return false;
        return helper(node->left, min_val, node->val) && helper(node->right, node->val, max_val);
    }
};
