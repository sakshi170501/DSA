class Solution {
public:
    int fibonacci(int n) {
        if (n == 0 || n == 1) {
            return n;
        }

        int ans = fibonacci(n - 1) + fibonacci(n - 2);
        return ans;
    }
    int memo(int n, vector<int>& dp) {
        if (n == 0 || n == 1) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        int ans = memo(n - 1, dp) + memo(n - 2, dp);
        dp[n] = ans;
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        int ans = memo(n, dp);

        return ans;
    }
};