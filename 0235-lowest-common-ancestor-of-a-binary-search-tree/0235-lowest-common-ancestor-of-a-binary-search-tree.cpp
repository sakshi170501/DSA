/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(p->val < root->val && q->val <root->val){
            TreeNode* leftAns= lowestCommonAncestor(root->left,p,q);
            if(leftAns!=NULL){
                return leftAns;
            }
        }
         if(p->val > root->val && q->val >root->val){
            TreeNode* rightAns= lowestCommonAncestor(root->right,p,q);
            if(rightAns!=NULL){
                return rightAns;
            }
        }
        return root;
        
        
    }
};