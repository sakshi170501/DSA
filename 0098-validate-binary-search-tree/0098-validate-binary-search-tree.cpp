
class Solution {
    bool solve(TreeNode* root, long long lb, long long rb) {
        if (!root) return true;

        return (root->val > lb && root->val < rb)
            && solve(root->left, lb, root->val)
            && solve(root->right, root->val, rb);
    }

public:
    bool isValidBST(TreeNode* root) {
        long long lb = LLONG_MIN;
        long long rb = LLONG_MAX;

        return solve(root, lb, rb);
    }
};
