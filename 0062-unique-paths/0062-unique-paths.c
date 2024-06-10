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
            dp[i][j] = -1;
        }
    }
    int result =  fun(m-1,n-1,dp);
    free(dp);
    return result;
}