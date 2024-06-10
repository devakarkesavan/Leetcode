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
int fun1(int ind,int* dp,int* nums){
    if(ind==1){
        return nums[1];
    }
    if(ind<=0){
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
    int *dp1 = (int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++){
        dp1[i] = -1;
    }
    // dp[0] = nums[0];
    // int prev = nums[0],prev2 = 0,curr;
    // for(int i=1;i<n;i++){
    //     int take = nums[i];
    //     if(i>1){
    //         take+=dp[i-2];
    //     }
    //     int nt = dp[i-1];
    //     dp[i] = max(take,nt);
    // }
    // for(int i=1;i<n;i++){
    //     int take = nums[i];
    //     if(i>1){
    //         take+=prev2;
    //     }
    //     int nt = prev;
    //     curr = max(take,nt);
    //     prev2 = prev;
    //     prev = curr;
    // }
    // return prev;
    int result1 = fun(n-1,dp,nums);
    int result2 = fun1(n-2,dp1,nums);
    free(dp);
    free(dp1);
    return max(result1,result2);
}