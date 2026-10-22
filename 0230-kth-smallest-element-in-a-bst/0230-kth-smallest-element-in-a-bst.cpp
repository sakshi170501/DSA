class Solution {
public:
    void storeinorder(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }

        storeinorder(root->left, inorder);
        inorder.push_back(root->val);
        storeinorder(root->right, inorder);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        storeinorder(root, inorder);

        return inorder[k - 1];
    }
};