class Solution {
private:
    bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<int>&check,vector<vector<int>>&graph){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,check,graph)){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // int n= graph.size();
        // vector<int>vis(n,0);
        // vector<int>pathVis(n,0);
        // vector<int>check(n,0);
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(i,vis,pathVis,check,graph);
        //     }
        // }
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(check[i]==1){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        int n = graph.size();
        vector<int>adjRev[n];
        
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
        
    }
};