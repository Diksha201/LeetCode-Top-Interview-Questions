class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char val = board[i][j];
            if (val == '.') continue;

            // Row check
            if (rows[i].count(val)) return false;
            rows[i].insert(val);

            // Column check
            if (cols[j].count(val)) return false;
            cols[j].insert(val);

            // Box check
            int boxIdx = (i / 3) * 3 + (j / 3);
            if (boxes[boxIdx].count(val)) return false;
            boxes[boxIdx].insert(val);
        }
    }

    return true;
}
};