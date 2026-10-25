
class Info {
public:
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
};

class Solution {
public:
    Info solve(TreeNode* root, int &sum) {
        if (root == NULL) {
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            return temp;
        }

        Info leftAns = solve(root->left, sum);
        Info rightAns = solve(root->right, sum);

        Info currentAns;

        currentAns.minVal = min(root->val,
                            min(leftAns.minVal, rightAns.minVal));

        currentAns.maxVal = max(root->val,
                            max(leftAns.maxVal, rightAns.maxVal));

        currentAns.sum = root->val + leftAns.sum + rightAns.sum;
        currentAns.isBST = false;

        if (root->val > leftAns.maxVal &&
            root->val < rightAns.minVal &&
            leftAns.isBST &&
            rightAns.isBST) {

            currentAns.isBST = true;
            sum = max(sum, currentAns.sum);
        }

        return currentAns;
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};
