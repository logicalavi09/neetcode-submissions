class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        int ans = 0;

        for(auto& num : nums){
            pq.push(num);
        }

        while(k > 0){
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};
