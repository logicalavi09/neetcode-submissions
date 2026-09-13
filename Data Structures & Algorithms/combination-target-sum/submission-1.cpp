class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int>& nums, int target, int idx){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0 || idx == nums.size()){
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, target-nums[idx], idx);
        temp.pop_back();
        solve(nums, target, idx+1);
        
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums, target, 0);
        return ans;
    }
};
