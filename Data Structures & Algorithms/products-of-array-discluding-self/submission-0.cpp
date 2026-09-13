class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        // prefix calc
        prefix[0] = 1;
        for(int i=1; i<n; i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        // suffix calc;
        suffix[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = (prefix[i] * suffix[i]);
        }
        return ans;
    }
};
