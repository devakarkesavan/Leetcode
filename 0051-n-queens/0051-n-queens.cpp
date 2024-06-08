class Solution {
public:
    void fun(int col,vector<vector<string>>&ans,vector<string>&board,vector<int>&leftRow,vector<int>&lowerDiagonal,vector<int>&upperDiagonal){
        if(col==board.size()){
            ans.push_back(board);
            return;
        }
        int n=  board.size();
        for(int row=0;row<board.size();row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 + col-row]==0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                fun(col+1,ans,board,leftRow,lowerDiagonal,upperDiagonal);
                board[row][col]='.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<int>leftRow(n,0);
        vector<int>LowerDiagonal(2*n-1,0);
        vector<int>UpperDiagonal(2*n-1,0);
        fun(0,ans,board,leftRow,LowerDiagonal,UpperDiagonal);
        return ans;
    }
};