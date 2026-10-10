
class Solution {
public:
    int getIndex(int element, vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int& preorderindex, int inorderstart, int inorderend) {
        if (inorderstart > inorderend) {
            return NULL;
        }

        int element = preorder[preorderindex];
        preorderindex++;

        TreeNode* root = new TreeNode(element);

        int elementinsideinorder = getIndex(element, inorder);

        root->left = buildTree(preorder, inorder, preorderindex,
                               inorderstart, elementinsideinorder - 1);

        root->right = buildTree(preorder, inorder, preorderindex,
                                elementinsideinorder + 1, inorderend);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex = 0;

        return buildTree(preorder, inorder, preorderindex,
                         0, inorder.size() - 1);
    }
};
