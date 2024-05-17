class Solution {
// private:
//     void dfs(int row, int col,vector<vector<int>>&image,vector<vector<int>>&ans,vector<vector<int>>&vis,int ini,int color,int dr[],int dc[]){
//         ans[row][col] = color;
//         vis[row][col] = 1;
//         int n = ans.size();
//         int m = ans[0].size();
//         for(int i=0;i<4;i++){
//             int nrow = row+dr[i];
//             int ncol = col+dc[i];
//             if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==ini && ans[nrow][ncol]!=color){
//                 dfs(nrow,ncol,image,ans,vis,ini,color,dr,dc);
//             }
//         }
//     }
private:
    void bfs(int row,int col,vector<vector<int>>&image,vector<vector<int>>& ans,vector<vector<int>>&vis,int ini,int color,int dr[],int dc[]){
        ans[row][col] = color;
        int n = ans.size();
        int m = ans[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r = nrow+dr[i];
                int c = ncol+dc[i];
                if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && image[r][c]==ini && ans[r][c]!=color){
                    ans[r][c] = color;
                    vis[r][c] = ini;
                    q.push({r,c});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColour = image[sr][sc];
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        vector<vector<int>>ans = image;
        vector<vector<int>>vis(n,vector<int>(m,0));
        bfs(sr,sc,image,ans,vis,initialColour,color,dr,dc);
        return ans;
        
    }
};