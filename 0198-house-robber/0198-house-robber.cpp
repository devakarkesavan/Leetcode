class Solution {
public:
    int fun(int ind,vector<int>&dp,vector<int>&nums){
        if(ind==0){
            return nums[0];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int not_take = 0+fun(ind-1,dp,nums);
        int take =nums[ind] + fun(ind-2,dp,nums);
        return dp[ind] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return fun(n-1,dp,nums);
    }
};