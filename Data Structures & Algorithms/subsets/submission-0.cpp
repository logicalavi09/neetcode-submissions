class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& temp){
        if(idx == nums.size()){
            ans.push_back(temp);
            return ans;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx+1, ans, temp);
        temp.pop_back();
        solve(nums, idx+1, ans, temp);

        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        return solve(nums, 0, ans, temp);
    }
};
