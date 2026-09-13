class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int directions[4][2] = {
            {1, 0},   
            {-1, 0},  
            {0, 1},   
            {0, -1}   
        };

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (grid[nr][nc] != 2147483647)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;

                q.push({nr, nc});
            }
        }
    }
};