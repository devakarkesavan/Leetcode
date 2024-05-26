class DisjointSet{
    
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void findUnion(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u==ulp_v){
            return ;
        }
        if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u==ulp_v){
            return ;
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
private:
    bool isValid(int row,int col,int n){
        return row>=0 && col>=0 && row<n && col<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                for(int ind=0;ind<4;ind++){
                    int row = dr[ind]+i;
                    int col = dc[ind]+j;
                    if(isValid(row,col,n) && grid[row][col]==1){
                        int nodeNo = i*n + j;
                        int adjNo = row*n + col;
                        ds.UnionBySize(nodeNo,adjNo);
                    }
                }
            }
        }
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    continue;
                }
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                set<int>components;
                for(int ind=0;ind<4;ind++){
                    int row = dr[ind]+i;
                    int col = dc[ind]+j;
                    if(isValid(row,col,n)){
                         if(grid[row][col]==1){
                             components.insert(ds.findParent(row*n+col));
                         }
                    }
                }
                int totSum = 0;
                for(auto it:components){
                    totSum+=ds.size[it];
                }
                mx = max(mx,totSum+1);
            }
        }
        for(int i=0;i<n*n;i++){
            mx = max(mx,ds.size[i]);
        }
        return mx;
    }
};