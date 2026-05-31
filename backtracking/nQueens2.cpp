class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n)
    {
        for(int i = row - 1; i >= 0; i--)
        {
            if(board[i][col] == 'Q')
            {
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board, int& count)
    {
        if(row == n)
        {
            count++;
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(isSafe(board, row, col, n))
            {
                board[row][col] = 'Q';

                solve(row + 1, n, board, count);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        int count = 0;

        solve(0, n, board, count);

        return count;
    }
};