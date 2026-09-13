class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalAvail = accumulate(gas.begin(), gas.end(), 0);
        int totalReq = accumulate(cost.begin(), cost.end(), 0);

        if(totalAvail < totalReq){
            return -1;
        }

        int total = 0;
        int result = 0;

        for(int i=0; i<gas.size(); i++){
            total += gas[i] - cost[i];

            if(total < 0){
                total = 0;
                result = i+1;
            }
        }
        return result;
    }
};
