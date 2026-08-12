class Solution {
public:
    int solve(int amount, int index, vector<int>& coins,
              vector<vector<int>>& dp) {

        // Amount completed
        if (amount == 0) {
            return 1;
        }

        // No coins left
        if (index >= coins.size()) {
            return 0;
        }

        // Already calculated
        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }

        // Include
        int include = 0;

        if (coins[index] <= amount) {
            include = solve(amount - coins[index],
                            index,
                            coins,
                            dp);
        }

        // Exclude
        int exclude = solve(amount,
                            index + 1,
                            coins,
                            dp);

        dp[index][amount] = include + exclude;

        return dp[index][amount];
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(amount, 0, coins, dp);
    }
};