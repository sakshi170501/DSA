
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
    bool solvetd(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
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

        bool ans = solvetd(nums, target, i, dp);

        return ans;
    }
};
