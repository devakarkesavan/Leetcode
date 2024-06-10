long min(long a,long b){
    return (a>b) ? b : a;
}
long fun(int i, int j, int** grid, long** dp) {
    if (i == 0 && j == 0) {
        return grid[0][0];
    }
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    long up = grid[i][j] + fun(i - 1, j, grid, dp);
    long left = grid[i][j] + fun(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int m = *gridColSize;
    long** dp = (long**)malloc(n*sizeof(long*));
    for(int i=0;i<n;i++){
        dp[i] = (long*)malloc(m*sizeof(long));
        for(int j=0;j<m;j++){
            dp[i][j] = -1;
        }
    }
    int result = fun(n-1,m-1,grid,dp);
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    return (int)result;
}