class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int include = nums[index] + solve(nums, index + 2, dp);
        int exclude = 0 + solve(nums, index + 1, dp);
        dp[index] = max(include, exclude);
        return dp[index];
    }
    int solveusingtabulation(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        vector<int> dp(nums.size()+1, -1);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int temp=0;
            if(i+2<=n){
                temp=dp[i+2];
            }
            int include = nums[i] + temp;
            int exclude = 0 +dp[index+1];
            dp[i] = max(include, exclude);
        }
        return dp[0];
    }
     int solveusingspace(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        // vector<int> dp(nums.size()+1, -1);
        int next1=0;
        int next2=0;
        int curr;

        for (int i = n - 1; i >= 0; i--) {
            int temp=0;
            if(i+2<=n){
                temp=next2;
            }
            int include = nums[i] + temp;
            int exclude = 0 +next1;
            curr = max(include, exclude);
            next2=next1;
            next1=curr;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int index = 0;
        vector<int> dp(nums.size()+1, -1);
        int answer = solveusingspace(nums);
        return answer;
    }
};
