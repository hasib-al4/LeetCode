class Solution {
public:
    void queens(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++) {
            if(!leftRow[row] && !upperDiag[(n - 1) + (col - row)] && !lowerDiag[col + row]) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiag[(n - 1) + (col - row)] = 1;
                lowerDiag[col + row] = 1;
                queens(col + 1, board, ans, n, leftRow, upperDiag, lowerDiag);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiag[(n - 1) + (col - row)] = 0;
                lowerDiag[col + row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string arr(n,'.');
        vector<int> leftRow(n, 0), upperDiag((2 * n) - 1, 0), lowerDiag((2 * n) - 1, 0);
        for(int i = 0; i < n; i++) {
            board[i] = arr;
        }
        queens(0, board, ans, n, leftRow, upperDiag, lowerDiag);
        return ans;
    }
};