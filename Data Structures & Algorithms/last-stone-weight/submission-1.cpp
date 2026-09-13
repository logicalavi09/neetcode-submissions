class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;

        if(stones.size() == 1){
            return stones[0];
        }

        for(int i=0; i<n; i++){
            pq.push(stones[i]);
        }

        while(!pq.empty()){
            int greater = pq.top();
            pq.pop();
            int sec_greater = pq.top();
            pq.pop();

            pq.push(greater - sec_greater);

            if(pq.size() == 1){
                return pq.top();
            }
        }
        return 1;
    }
};
