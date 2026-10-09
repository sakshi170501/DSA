/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int getheight(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftDepth=getheight(root->left);
    int rightDepth=getheight(root->right);
    int ans=max(leftDepth,rightDepth)+1;
    return ans;
   }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;

        }
        int leftHeight=getheight(root->left);
        int rightHeight=getheight(root->right);
        int absDiff=abs(leftHeight-rightHeight);
        if(absDiff>1){
            return false;
        }
        else{
            bool leftans=isBalanced(root->left);
            bool rightans=isBalanced(root->right);
            if(leftans==true && rightans==true){
                return true;
            }
            else{
                return false;
            }

        }
    }
};