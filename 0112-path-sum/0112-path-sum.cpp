class Solution {
public:
    bool solve(TreeNode* root, int targetSum, int sum) {

        // Empty node
        if (root == NULL) {
            return false;
        }

        // Add the current node's value
        sum = sum + root->val;

        // Check only at a leaf node
        if (root->left == NULL && root->right == NULL) {
            return sum == targetSum;
        }

        bool leftans = solve(root->left, targetSum, sum);
        bool rightans = solve(root->right, targetSum, sum);

        return leftans || rightans;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum, 0);
    }
};