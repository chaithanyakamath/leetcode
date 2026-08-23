class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row[9], col[9], box[9];

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')  continue;
                char curr = board[i][j];

                if(row[i].count(curr))  return false;
                row[i].insert(curr);

                if(col[j].count(curr))  return false;
                col[j].insert(curr);

                int boxIdx = (i/3)*3 + (j/3);
                if(box[boxIdx].count(curr)) return false;
                box[boxIdx].insert(curr);
            }
        }
        return true;
    }
};