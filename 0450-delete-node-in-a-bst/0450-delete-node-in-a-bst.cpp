/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getMax(TreeNode* root){
        if(root==NULL){
            return -1;

        }
        while(root->right!=NULL){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                TreeNode* temp = root;
                delete temp;
                return NULL;
            }
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root;
                TreeNode* child = root->left;
                delete temp;
                return child;
            }
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root;
                TreeNode* child = root->right;
                delete temp;
                return child;
            }
              if (root->left != NULL && root->right != NULL) {
                int replaceValue=getMax(root->left);
                root->val=replaceValue;
                root->left=deleteNode(root->left,replaceValue);
                return root;

               
            }

        }

        else {
            if (key > root->val) {
                root->right = deleteNode(root->right, key);
            } else {
                root->left = deleteNode(root->left, key);
            }
        }
        return root;
    }
};