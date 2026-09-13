class Solution {
public:
    vector<int> memo;
    int dp(vector<int>& nums, int idx){
        int n = nums.size();
        if(idx >= n){
            return 0;
        }

        if(memo[idx] != -1){
            return memo[idx];
        }

        int rob = nums[idx] + dp(nums, idx+2);
        int skip = dp(nums, idx+1);

        return memo[idx] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return dp(nums, 0);
    }
};
