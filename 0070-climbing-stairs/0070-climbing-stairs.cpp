class Solution {
public:
    int fun(int ind,vector<int>&dp){
        if(ind<=1){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int first = fun(ind-1,dp);
        int second = fun(ind-2,dp);
        return dp[ind] =  first+second;
    }
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        vector<int>dp(n+1,-1);
        fun(n,dp);
        return dp[n];
    }
};