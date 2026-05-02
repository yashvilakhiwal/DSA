class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        int srow = 0, scol = 0;
        int erow = matrix.size() - 1;
        int ecol = matrix[0].size() - 1;

        while (srow <= erow && scol <= ecol)
        {
            // Top row: left to right
            for (int i = scol; i <= ecol; i++)
                result.push_back(matrix[srow][i]);

            // Right col: top to bottom
            for (int i = srow + 1; i <= erow; i++)
                result.push_back(matrix[i][ecol]);

            // Bottom row: right to left
            for (int i = ecol - 1; i >= scol; i--)
            {
                if (srow == erow) break;
                result.push_back(matrix[erow][i]);
            }

            // Left col: bottom to top
            for (int i = erow - 1; i >= srow + 1; i--)
            {
                if (scol == ecol) break;
                result.push_back(matrix[i][scol]);
            }

            srow++; scol++; erow--; ecol--;
        }

        return result;
    }
};