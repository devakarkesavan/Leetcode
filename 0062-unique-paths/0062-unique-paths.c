int fun(int i,int j,int** dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left = fun(i,j-1,dp);
    int up = fun(i-1,j,dp);
    return dp[i][j] = left+up;
}

int uniquePaths(int m, int n) {
    int **dp = (int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        dp[i] = (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
    // int result =  fun(m-1,n-1,dp);
    // free(dp);
    // return result;
    dp[0][0] = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[0][0] = 1;
                continue;
            }
            else{
            int left=0,up = 0;
            if(j-1>=0){
             left = dp[i][j-1];
            }
            if(i-1>=0){
             up = dp[i-1][j];
            }
            dp[i][j] = left+up;
            }
        }
    }
    return dp[m-1][n-1];
}