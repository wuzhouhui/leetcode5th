#include <vector>
#include <cstdlib>

using std::vector;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        signed char cnt[10];
        int i, j, m, n;

        for (i = 0; i < 9; ++i) {
            memset(cnt, 1, sizeof(cnt));
            for (j = 0; j < 9; ++j)
                if (board[i][j] == '.')
                    continue;
                else if (--cnt[board[i][j] - '0'] < 0)
                    return(false);
        }
        for (j = 0; j < 9; ++j) {
            memset(cnt, 1, sizeof(cnt));
            for (i = 0; i < 9; ++i)
                if (board[i][j] == '.')
                    continue;
                else if (--cnt[board[i][j] - '0'] < 0)
                    return(false);
        }
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; ++j) {
                memset(cnt, 1, sizeof(cnt));
                for (m = i * 3; m < i * 3 + 3; ++m) {
                    for (n = j * 3; n < j * 3 + 3; ++n) {
                        if (board[m][n] == '.')
                            continue;
                        else if (--cnt[board[m][n] - '0'] < 0)
                            return(false);
                    }
                }
            }
        }
        return(true);
    }
};

int main(void){}
