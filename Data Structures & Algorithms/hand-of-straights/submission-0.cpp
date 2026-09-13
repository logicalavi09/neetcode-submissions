class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> mp;

        for (int x : hand)
            mp[x]++;

        while (!mp.empty()) {

            int start = mp.begin()->first;
            int cnt = mp.begin()->second;

            for (int x = start; x < start + groupSize; x++) {

                if (mp.find(x) == mp.end() || mp[x] < cnt)
                    return false;

                mp[x] -= cnt;

                if (mp[x] == 0)
                    mp.erase(x);
            }
        }

        return true;
    }
};