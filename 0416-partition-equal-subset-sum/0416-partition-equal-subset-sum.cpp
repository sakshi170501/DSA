
class Solution {
public:
    bool solve(vector<int>& nums, int target, int i) {
        // Base cases
        if (target < 0 || i >= nums.size()) {
            return false;
        }

        if (target == 0) {
            return true;
        }

        // Include current element
        bool inc = solve(nums, target - nums[i], i + 1);

        // Exclude current element
        bool exc = solve(nums, target, i + 1);

        return inc || exc;
    }
    bool solvetd(vector<int>& nums, int target, int i,
                 vector<vector<int>>& dp) {
        // Base cases
        if (target < 0 || i >= nums.size()) {
            return false;
        }

        if (target == 0) {
            return true;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        // Include current element
        bool inc = solvetd(nums, target - nums[i], i + 1, dp);

        // Exclude current element
        bool exc = solvetd(nums, target, i + 1, dp);

        dp[i][target] = inc || exc;
        return dp[i][target];
    }

bool solvebu(vector<int>& nums, int target) {
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: target = 0 is always possible
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int t = 1; t <= target; t++) {

            bool inc = false;

            // Include current element
            if (t - nums[i] >= 0) {
                inc = dp[i + 1][t - nums[i]];
            }

            // Exclude current element
            bool exc = dp[i + 1][t];

            dp[i][t] = inc || exc;
        }
    }

    return dp[0][target];
}

bool solveso(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int>curr(target+1,0);
    vector<int>next(target+1,0);

    // vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: target = 0 is always possible
    for (int i = 0; i <= n; i++) {
        next[0] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int t = 1; t <= target; t++) {

            bool inc = false;

            // Include current element
            if (t - nums[i] >= 0) {
                inc = next[t - nums[i]];
            }

            // Exclude current element
            bool exc = next[t];

            curr[t] = inc || exc;
        }
        next=curr;
    }

    return curr[target];
}

 

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // Odd sum cannot be divided equally
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int i = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        bool ans = solveso(nums, target);

        return ans;
    }
};
