class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int>& nums, int target, int idx){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            temp.push_back(nums[i]);
            solve(nums, target-nums[i], i);
            temp.pop_back(); //Backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums, target, 0);
        return ans;
    }
};
