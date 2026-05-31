class Solution {
public:
    void helper(vector<vector<int>> &maze, int r, int c,
                string path, vector<string> &ans) {

        int n = maze.size();

        // invalid cell
        if (r < 0 || c < 0 || r >= n || c >= n ||
            maze[r][c] == 0 || maze[r][c] == -1) {
            return;
        }

        // destination reached
        if (r == n - 1 && c == n - 1) {
            ans.push_back(path);
            return;
        }

        // mark visited
        maze[r][c] = -1;

        helper(maze, r + 1, c, path + "D", ans); // Down
        helper(maze, r, c - 1, path + "L", ans); // Left
        helper(maze, r, c + 1, path + "R", ans); // Right
        helper(maze, r - 1, c, path + "U", ans); // Up

        // unmark visited (backtrack)
        maze[r][c] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        vector<string> ans;

        int n = maze.size();

        if (maze[0][0] == 0 || maze[n-1][n-1] == 0)
            return ans;

        helper(maze, 0, 0, "", ans);

        return ans;
    }
};