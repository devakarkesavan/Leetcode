class Solution {
public:
    void flip_row(vector<vector<int>>&grid,int i){
        for(int j=0;j<grid[0].size();j++){
            grid[i][j] = !grid[i][j];
        }
    }
    void flip_col(vector<vector<int>>&grid,int j){
        for(int i=0;i<grid.size();i++){
            grid[i][j] = !grid[i][j]; 
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                flip_row(grid,i);
            }
        }
        
        for(int j=1;j<m;j++){
            int count = 0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==0){
                    count++;
                }
            }
            if(count>n/2){
                flip_col(grid,j);
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<m;j++){
                str+=to_string(grid[i][j]);
            }
            sum+= stoi(str,0,2);
        }
        return sum;
    }
};