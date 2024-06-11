int min(int a, int b) {
    return (a > b) ? b : a;
}

int minFallingPathSum(int** A, int n,int* m) {
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        dp[0][i] = A[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int prevCol = (j >= 1) ? dp[i-1][j-1] + A[i][j] : INT_MAX;
            int nextCol = (j < n-1) ? dp[i-1][j+1] + A[i][j] : INT_MAX;
            int sameCol = dp[i-1][j] + A[i][j];
            dp[i][j] = min(prevCol, min(nextCol, sameCol));
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++) {
        ans = min(ans, dp[n-1][j]);
    }

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return ans;
}