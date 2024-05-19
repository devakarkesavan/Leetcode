class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int dr[],int dc[]){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int r = row+dr[i];
            int c = col+dc[i];
            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && grid[r][c]==1){
                dfs(r,c,vis,grid,dr,dc);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,vis,grid,dr,dc);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,vis,grid,dr,dc);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0,j,vis,grid,dr,dc);
            }
            if(grid[n-1][j]==1){
                dfs(n-1,j,vis,grid,dr,dc);
            }
        }
        int cnt= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};