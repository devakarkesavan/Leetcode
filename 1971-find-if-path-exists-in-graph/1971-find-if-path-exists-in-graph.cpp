class Solution {
private:
    bool dfs(vector<int> &vis,vector<vector<int>> &adj,int s,int d){
        if(s==d) return true;
        vis[s] = 1;
        for(auto it: adj[s]){
            if(!vis[it]){
                if(dfs(vis,adj,it,d)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n,vector<int>());
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        return dfs(vis,adj,source,destination);
    }
};