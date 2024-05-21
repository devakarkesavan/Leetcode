class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dist[src] = 0;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int distance = it.second.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(auto it:adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(distance+wt < dist[v] && stops<=k){
                    dist[v] = distance+wt;
                    q.push({stops+1,{v,distance+wt}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};