class Solution {
public:
    bool acceptable(int row, int col, vector<string> board, int n) {
        int dumRow = row;
        int dumCol = col;
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = dumRow;
        col = dumCol;
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        col = dumCol;
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void queens(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++) {
            if(acceptable(row, col, board, n)) {
                board[row][col] = 'Q';
                queens(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string arr(n,'.');
        for(int i = 0; i < n; i++) {
            board[i] = arr;
        }
        queens(0, board, ans, n);
        return ans;
    }
};