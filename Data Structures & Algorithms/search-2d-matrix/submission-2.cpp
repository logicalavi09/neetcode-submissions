class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){ //i = 0, 10, 2
            int low = 0;
            int high = n-1;

            // i=0
            //low = 0
            //high = 3

            while(low <= high){   //while(0 <= 3)
                int mid = low + (high - low)/2;
                //mid = 0 + (3-0)/2;
                //mid = 1;

                if(matrix[i][mid] == target){
                    //matrix[0][mid] != targrt
                    return true;
                }

                else if(matrix[i][mid] < target){ //matrix[0][1] !< target
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
