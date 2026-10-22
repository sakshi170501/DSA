class Solution {
public:
    void storeInorder(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }

        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }

    void updateTree(TreeNode* root, vector<int>& inorder, int& index) {
        if (root == NULL) {
            return;
        }

        updateTree(root->left, inorder, index);

        root->val = inorder[index];
        index++;

        updateTree(root->right, inorder, index);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        vector<int> inorder;
        storeInorder(root, inorder);

        int n = inorder.size();


        for (int i = n - 1; i >= 0; i--) {
            int currVal=inorder[i];
            int nextval=0;
            if(i+1<n){
                nextval=inorder[i+1];
            }
            int sum=currVal+nextval;
            inorder[i]=sum;
        }

        int index = 0;
        updateTree(root, inorder, index);

        return root;
    }
};