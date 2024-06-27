class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
         int n = edges.size(); 
         vector<int>adj[n+2];
         for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n+1;i++){
            if(adj[i].size()>1) return i;
        }
        return 0;
    }
};