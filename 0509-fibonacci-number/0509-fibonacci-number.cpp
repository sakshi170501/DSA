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
    int tabulation(int n, vector<int>&dp){
        if(n==0) return 0;
        if(n==1) return 1;
       
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int ans=dp[i-1]+dp[i-2];
            dp[i]=ans;
        }
        return dp[n];

    }
    int space(int n){
        if(n==0) return 0;
        if(n==1) return 1;
       
        int prev1=1;
        int prev2=0;
        int curr=-1;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;

    }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        int ans =space(n);

        return ans;
    }
};