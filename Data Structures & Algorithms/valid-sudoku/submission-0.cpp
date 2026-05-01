class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> row_map(9);
        vector<unordered_map<char, int>> col_map(9);
        vector<unordered_map<char, int>> box_map(9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (!row_map[i].count(board[i][j])) {
                    row_map[i][board[i][j]]++;
                } else {
                    return false;
                }

                if (!col_map[j].count(board[i][j])) {
                    col_map[j][board[i][j]]++;
                } else {
                    return false;
                }

                if (!box_map[(i / 3) * 3 + (j / 3)].count(board[i][j])) {
                    box_map[(i / 3) * 3 + (j / 3)][board[i][j]]++;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
