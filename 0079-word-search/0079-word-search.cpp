class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& vis, const string& word, vector<vector<char>>& board, int index) {
        if (index == word.size() - 1) {
            return true;
        }

        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[index + 1]) {
                if (dfs(nrow, ncol, vis, word, board, index + 1)) {
                    return true;
                }
            }
        }

        // Backtrack
        vis[row][col] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(i, j, vis, word, board, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};