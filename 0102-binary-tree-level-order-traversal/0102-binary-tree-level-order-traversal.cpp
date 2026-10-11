
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        vector<int> temp;
        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == NULL) {
                ans.push_back(temp);
                temp.clear();

                if (!q.empty()) {
                    q.push(NULL);
                }
            } 
            else {
                temp.push_back(front->val);

                if (front->left != NULL) {
                    q.push(front->left);
                }

                if (front->right != NULL) {
                    q.push(front->right);
                }
            }
        }

        return ans;
    }
};
