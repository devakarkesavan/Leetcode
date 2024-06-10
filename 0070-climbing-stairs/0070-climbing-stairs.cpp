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
        vector<long long int>dp(n+1,-1);
        long long int prev = 1;
        long long int prev2 = 1;
        long long int curr;
        for(int i=2;i<=n;i++){
            curr = prev+prev2;
            prev2 = prev;
            prev = curr;
        }
        return (int)prev;
    }
};