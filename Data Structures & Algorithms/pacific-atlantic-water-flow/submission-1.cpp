class Solution {
public:
    int n, m;

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited,
             vector<pair<int, int>> starts) {

        queue<pair<int, int>> q;

        for (auto cell : starts) {
            int i = cell.first;
            int j = cell.second;

            if (!visited[i][j]) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }

        int dir[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!q.empty()) {

            auto [i, j] = q.front();
            q.pop();

            for (auto& d : dir) {

                int ni = i + d[0];
                int nj = j + d[1];

                if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                    continue;

                if (visited[ni][nj])
                    continue;

                if (heights[ni][nj] < heights[i][j])
                    continue;

                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        vector<pair<int, int>> pacificStart;
        vector<pair<int, int>> atlanticStart;

        for (int i = 0; i < n; i++) {
            pacificStart.push_back({i, 0});
            atlanticStart.push_back({i, m - 1});
        }

        for (int j = 0; j < m; j++) {
            pacificStart.push_back({0, j});
            atlanticStart.push_back({n - 1, j});
        }

        bfs(heights, pacific, pacificStart);
        bfs(heights, atlantic, atlanticStart);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};