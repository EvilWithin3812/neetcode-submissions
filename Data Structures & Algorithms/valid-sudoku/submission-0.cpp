class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            set<char> st;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                else if (st.count(board[row][col]) == 0) {
                    st.insert(board[row][col]);
                } else {
                    return false;
                }
            }
        }

        for (int col = 0; col < 9; col++) {
            set<char> st;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.')
                    continue;
                else if (st.count(board[row][col]) == 0) {
                    st.insert(board[row][col]);
                } else {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<char> st;

                for (int row = i; row < i + 3; row++) {
                    for (int col = j; col < j + 3; col++) {
                        if (board[row][col] == '.')
                            continue;
                        else if (st.count(board[row][col]) == 0) {
                            st.insert(board[row][col]);
                        } else {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
