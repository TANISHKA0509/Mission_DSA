class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        dfs(root, "", paths);
        return paths;
    }

private:
    void dfs(TreeNode* node, string currentPath, vector<string>& paths) {
        if (!node) return;

        if (currentPath.empty()) {
            currentPath += to_string(node->val);
        } else {
            currentPath += "->" + to_string(node->val);
        }

        if (!node->left && !node->right) {
            paths.push_back(currentPath);
            return;
        }

        dfs(node->left, currentPath, paths);
        dfs(node->right, currentPath, paths);
    }
};
