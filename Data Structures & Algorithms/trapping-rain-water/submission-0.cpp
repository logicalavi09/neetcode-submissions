class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        int ans = 0;

        int maxL=0, maxR = 0;
        for(int i=0; i<n; i++){     //0,1,2,3,4...
            maxL = max(maxL, height[i]);  //maxL = [0,2,2,3,3,3,3,3,3,3]
            leftMax[i] = maxL;    //leftMax=[0,2,2,3,3,3,3,3,3,3]
        }

        for(int i=n-1; i>=0; i--){
            maxR = max(maxR, height[i]);  
            rightMax[i] = maxR;    //[1,2,3,1,0,1,3,0,2,0]
        }
        for(int i=0; i<n; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};
