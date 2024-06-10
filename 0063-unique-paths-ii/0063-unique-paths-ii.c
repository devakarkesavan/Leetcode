int fun(int i,int j,int** obstacleGrid,int** dp){
    if(i>=0 && j>=0 && obstacleGrid[i][j]==1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left = fun(i,j-1,obstacleGrid,dp);
    int up = fun(i-1,j,obstacleGrid,dp);
    return dp[i][j] = up+left;
}
int uniquePathsWithObstacles(int** obstacleGrid, int n, int* s) {
    int m = *s;
    int **dp = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        dp[i] = (int*)malloc(m*sizeof(int));
        for(int j=0;j<m;j++){
            dp[i][j] = -1;
        }
    }
    int result = fun(n-1,m-1,obstacleGrid,dp);
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}