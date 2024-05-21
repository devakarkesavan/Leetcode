class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        dist[0][0] = 0;
        
        pq.push({0,{0,0}});
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto it = pq.top();
            
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            
            if(row==n-1 && col==m-1){
                return diff;
            }
            
            for(int i=0;i<4;i++){
                int r = row+dr[i];
                int c = col+dc[i];
                
                if(r>=0 && c>=0 && r<n && c<m){
                    int minEffort = max(abs(heights[row][col]-heights[r][c]),diff);
                    if(minEffort < dist[r][c]){
                        dist[r][c] = minEffort;
                        pq.push({minEffort,{r,c}});
                    }
                }
            }
        }
        return -1;
    }
};