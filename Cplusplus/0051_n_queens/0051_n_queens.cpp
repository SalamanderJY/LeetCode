class Solution {
private:

void backtracking(int n, int row, vector<string>& chessboard, vector<vector<string>>& result) {
    if (row == n) {
        result.push_back(chessboard);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(row, col, chessboard, n)) {
            chessboard[row][col] = 'Q';
            backtracking(n, row + 1, chessboard, result);
            chessboard[row][col] = '.';
        }
    }
}

bool isValid(int row, int col, vector<string>& chessboard, int n) {
    int count = 0;
    // check out column
    for (int i = 0; i < row; i++) { 
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    // check out 45 angle
    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // check out 135 angle
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        vector<vector<string>> result;
        backtracking(n, 0, chessboard, result);
        return result;
    }
};
