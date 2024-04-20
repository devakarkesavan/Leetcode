class Solution {
    vector<vector<int>> ans;
private:
    void dfs(int i, int j, int &r1, int &c1, int &r2, int &c2, vector<vector<int>> &land) {
        int n = land.size();
        int m = land[0].size();
        if (i >= 0 && i < n && j >= 0 && j < m && land[i][j] == 1) { // Boundary check
            land[i][j] = 2;
            r1 = min(r1, i), c1 = min(c1, j), r2 = max(r2, i), c2 = max(c2, j);
            dfs(i + 1, j, r1, c1, r2, c2, land); // Recursive call with boundary check
            dfs(i, j + 1, r1, c1, r2, c2, land); // Recursive call with boundary check
            dfs(i - 1, j, r1, c1, r2, c2, land); // Recursive call with boundary check
            dfs(i, j - 1, r1, c1, r2, c2, land); // Recursive call with boundary check
        }
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    int r1 = i, c1 = j, r2 = i, c2 = j;
                    dfs(i, j, r1, c1, r2, c2, land);
                    ans.push_back({r1, c1, r2, c2});   
                }
            }
        }
        return ans;
    }
};
