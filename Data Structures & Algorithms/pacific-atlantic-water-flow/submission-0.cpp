class Solution {
public:
    int n, m;

    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<bool>>& visited) {

        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        if (visited[i][j])
            return;

        visited[i][j] = true;

        if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j])
            dfs(heights, i - 1, j, visited);

        if (i + 1 < n && heights[i + 1][j] >= heights[i][j])
            dfs(heights, i + 1, j, visited);

        if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j])
            dfs(heights, i, j - 1, visited);

        if (j + 1 < m && heights[i][j + 1] >= heights[i][j])
            dfs(heights, i, j + 1, visited);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, m - 1, atlantic);
        }

        for (int j = 0; j < m; j++) {
            dfs(heights, 0, j, pacific);
            dfs(heights, n - 1, j, atlantic);
        }

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