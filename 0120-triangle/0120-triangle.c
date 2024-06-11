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
    // int **dp = (int**)malloc(n*sizeof(int*));
    // for(int i=0;i<n;i++){
    //     dp[i] = (int*)malloc(n*sizeof(int));
    //     for(int j=0;j<n;j++){
    //         dp[i][j] = 0;
    //     }
    // }
    int *next =  (int*)malloc(n*sizeof(int));
    for(int j=0;j<n;j++){
         next[j] = 0;
    }
    for(int i=0;i<n;i++){
        next[i] = triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        int *curr =  (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
             curr[j] = 0;
        }
        for(int j=i;j>=0;j--){
            int d1 = next[j] + triangle[i][j];
            int d2 = next[j+1] + triangle[i][j];
            curr[j]= min(d1,d2);
        }
        next = curr;
    }
    return next[0];
    // int result = fun(0,0,dp,triangle,n);
    // for(int i=0;i<n;i++){
    //     free(dp[i]);
    // }
    // free(dp);
    // return result;
}