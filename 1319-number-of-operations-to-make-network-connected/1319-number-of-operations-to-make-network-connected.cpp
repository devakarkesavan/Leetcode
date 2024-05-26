class DisjointSet{
  vector<int>parent,size,rank;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            size.resize(n+1,1);
            for(int i=0;i<n+1;i++){
                parent[i] = i;
            }
        }
    
        int findParent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
    
        void findUnionBySize(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u==ulp_v){
                return;
            }
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra= 0;
        DisjointSet ds(n);
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u)==ds.findParent(v)){
                extra++;
            }
            else{
                ds.findUnionBySize(u,v);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i){
                cnt++;
            }
        }
        int ans = cnt-1;
        if(ans<=extra){
            return ans;
        }
        else{
            return -1;
        }
    }
};