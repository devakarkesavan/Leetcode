class Solution {
    private:
       void dfs(int row,int col,int n,int m,vector<vector<char>> &grid){
           if(row<0 || row>=n || col<0 || col>=m || grid[row][col]=='0'){
               return;
           }
           grid[row][col] = '0';
           dfs(row+1,col,n,m,grid);
           dfs(row,col+1,n,m,grid);
           dfs(row-1,col,n,m,grid);
           dfs(row,col-1,n,m,grid);           
       }

    public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0){
            return 0;
        }
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,n,m,grid);
                    count++;
                }
            }
        }
        return count;
    }
};