class Solution {
public:
    vector<int>memo;
    int dp(vector<int>& nums, int idx, int end){
        if(idx > end){
            return 0;
        }

        if(memo[idx] != -1){
            return memo[idx];
        }

        int rob = nums[idx] + dp(nums, idx+2, end);
        int skip = dp(nums, idx+1, end);

        return memo[idx] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }
        memo.resize(n, -1);
        int case1 = dp(nums, 0, n-2);

        // for(int i=0; i<memo.size(); i++){
        //     cout<<memo[i]<<" "<<endl;
        // }
        /*
        memo{1,2,3,-1,-1}
        */

        memo.assign(n,-1);
        int case2 = dp(nums, 1, n-1);

        // for(int i=0; i<memo.size(); i++){
        //     cout<<memo[i]<<" "<<endl; 
        /* 
        memo{-1, -1, -1, -1}
        */
        // }

        return max(case1, case2);
    }
};
