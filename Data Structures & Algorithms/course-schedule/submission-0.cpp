class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int node) {
        if (visited[node] == 1)
            return false;

        if (visited[node] == 2)
            return true;

        visited[node] = 1;

        for (int next : adj[node]) {
            if (!dfs(adj, visited, next))
                return false;
        }

        visited[node] = 2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);

        for (auto& pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];

            adj[v].push_back(u);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(adj, visited, i))
                return false;
        }

        return true;
    }
};