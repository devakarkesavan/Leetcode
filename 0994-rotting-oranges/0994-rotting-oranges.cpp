class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int tm = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(t,tm);
            for(int i=0;i<4;i++){
                int r = row+dr[i];
                int c = col+dc[i];
                if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && grid[r][c]==1){
                    vis[r][c] = 1;
                    q.push({{r,c},t+1});
                    cnt--;
                }
            }
        }
        return cnt==0 ? tm:-1;
    }
};