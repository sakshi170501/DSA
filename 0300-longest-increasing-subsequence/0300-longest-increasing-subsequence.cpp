class Solution {
public:
    int recursion(vector<int>& arr, int curr, int prev) {
        if (curr >= arr.size()) {
            return 0;
        }
        int include = 0;
        if (prev == -1 || arr[curr] > arr[prev]) {
            include = 1 + recursion(arr, curr + 1, curr);
        }
        int exclude = 0 + recursion(arr, curr + 1, prev);
        int finalans = max(include, exclude);
        return finalans;
    }
    int topdown(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp) {
        if (curr >= arr.size()) {
            return 0;
        }
        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev+1];
        }
        int include = 0;
        if (prev == -1 || arr[curr] > arr[prev]) {
            include = 1 + topdown(arr, curr + 1, curr, dp);
        }
        int exclude = 0 + topdown(arr, curr + 1, prev, dp);
        int finalans = max(include, exclude);
        dp[curr][prev + 1] = finalans;
        return finalans;
    }
    int bottomup(vector<int>& arr) {
        int n =arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || arr[curr] > arr[prev]) {
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = 0 + dp[curr+1][prev+1];
                int finalans = max(include, exclude);
                dp[curr][prev + 1] = finalans;
            
            }
        }
        return dp[0][0];

    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = bottomup(nums);
        return ans;
    }
};