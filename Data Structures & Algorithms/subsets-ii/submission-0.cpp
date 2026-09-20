class Solution {
public:

    void operatinDuplicate(vector<vector<int>>& ans) {
        sort(ans.begin(), ans.end());

        ans.erase(
            unique(ans.begin(), ans.end()),
            ans.end()
        );
    }

    vector<vector<int>> solve(vector<int>& nums, int idx,
                              vector<vector<int>>& ans,
                              vector<int>& temp) {

        if (idx == nums.size()) {
            ans.push_back(temp);
            return ans;
        }

        // Take
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, ans, temp);

        // Backtrack
        temp.pop_back();

        // Not take
        solve(nums, idx + 1, ans, temp);

        return ans;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        solve(nums, 0, ans, temp);

        operatinDuplicate(ans);

        return ans;
    }
};