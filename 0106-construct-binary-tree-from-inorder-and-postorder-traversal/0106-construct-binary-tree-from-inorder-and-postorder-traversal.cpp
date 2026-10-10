/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int getIndex(int element, vector<int>& inorder,
                 int inorderstart, int inorderend) {
        for (int i = inorderstart; i <= inorderend; i++) {
            if (inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder,
                        int& postorderindex, int inorderstart, int inorderend) {

        if (inorderstart > inorderend || postorderindex < 0) {
            return nullptr;
        }

        int element = postorder[postorderindex];
        postorderindex--;

        TreeNode* root = new TreeNode(element);

        int elementinsideinorder =
            getIndex(element, inorder, inorderstart, inorderend);

        // if (elementinsideinorder == -1) {
        //     return root;
        // }

        // Build the right subtree first
        root->right = buildTree(postorder, inorder, postorderindex,
                                elementinsideinorder + 1, inorderend);

        // Then build the left subtree
        root->left = buildTree(postorder, inorder, postorderindex,
                               inorderstart, elementinsideinorder - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        int postorderindex = postorder.size()- 1;

        return buildTree(postorder, inorder, postorderindex,
                         0, inorder.size() - 1);
    }
};