
class Solution {
public:
    void solve(TreeNode* root, int target, int sum,
               vector<int>& temp, vector<vector<int>>& ans) {

        if (root == NULL) {
            return;
        }

        sum = sum + root->val;
        temp.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == target) {
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }

        solve(root->left, target, sum, temp, ans);
        solve(root->right, target, sum, temp, ans);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> ans;

        solve(root, targetSum, sum, temp, ans);

        return ans;
    }
};