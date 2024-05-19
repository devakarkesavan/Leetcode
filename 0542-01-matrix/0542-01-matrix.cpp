class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int  n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col= q.front().first.second;
            int d = q.front().second;
            q.pop();
            dis[row][col] = d;
            for(int i=0;i<4;i++){
                int r = row+dr[i];
                int c = col+dc[i];
                if(r>=0 && c>=0 && r<n && c<m && !vis[r][c]){
                    vis[r][c] = 1;
                    q.push({{r,c},d+1});
                }
            }
        }
        return dis;
    }
};