int min(int a,int b){
    return (a>b) ? b : a;
}
int fun(int i,int j,int** dp, int** arr,int n){
    if(i==n-1){
        return arr[n-1][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int d1 = arr[i][j]+ fun(i+1,j,dp,arr,n);
    int d2 = arr[i][j]+ fun(i+1,j+1,dp,arr,n);
    return dp[i][j] = min(d1,d2);
}
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int n = triangleSize;
    int **dp = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        dp[i] = (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    int result = fun(0,0,dp,triangle,n);
    for(int i=0;i<n;i++){
        free(dp[i]);
    }
    free(dp);
    return result;
}