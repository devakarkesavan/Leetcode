int max(int a,int b){
    return (a>b) ? a : b;
}
int fun(int ind,int* dp,int* nums){
    if(ind==0){
        return nums[0];
    }
    if(ind<0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int nt = fun(ind-1,dp,nums);
    int take = nums[ind]+fun(ind-2,dp,nums);
    return dp[ind] = max(nt,take);
}
int rob(int* nums, int n) {
    int *dp = (int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++){
        dp[i] = -1;
    }
    int result =  fun(n-1,dp,nums);
    free(dp);
    return result;
}