class Solution {
public:
    void solve(TreeNode* root, TreeNode* &prev, int &ans) {
        if (root == NULL) return;

        solve(root->left, prev, ans);

        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        solve(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        int ans = INT_MAX;

        solve(root, prev, ans);

        return ans;
    }
};