class Solution {
public:

    bool checkRow(vector<vector<char>>& board,
                  int row, int col, char num) {

        for (int j = 0; j < 9; j++) {

            if (j != col && board[row][j] == num) {
                return false;
            }
        }

        return true;
    }


    bool checkColumn(vector<vector<char>>& board,
                     int row, int col, char num) {

        for (int i = 0; i < 9; i++) {

            if (i != row && board[i][col] == num) {
                return false;
            }
        }

        return true;
    }


    bool checkBox(vector<vector<char>>& board,
                  int row, int col, char num) {

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {

            for (int j = startCol; j < startCol + 3; j++) {

                if ((i != row || j != col) &&
                    board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    continue;
                }

                char num = board[i][j];

                if (!checkRow(board, i, j, num)) {
                    return false;
                }

                if (!checkColumn(board, i, j, num)) {
                    return false;
                }

                if (!checkBox(board, i, j, num)) {
                    return false;
                }
            }
        }

        return true;
    }
};