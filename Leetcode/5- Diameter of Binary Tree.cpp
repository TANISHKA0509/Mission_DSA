class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;

        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        diameter = std::max(diameter, leftHeight + rightHeight);

        return 1 + std::max(leftHeight, rightHeight);
    }
};
