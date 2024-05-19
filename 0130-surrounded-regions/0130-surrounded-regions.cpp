class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int r = row+dr[i];
            int c = col+dc[i];
            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && board[r][c]=='O'){
                dfs(r,c,vis,board);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O'){
                dfs(0,j,vis,board);
            }
            if(board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                dfs(i,0,vis,board);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};