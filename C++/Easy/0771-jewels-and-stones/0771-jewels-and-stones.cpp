class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = stones.size();
        unordered_map<char, int> count;
        int counts = 0;
        for (int i = 0; i < n; i++) {
            count[stones[i]]++;
        }
        for (int j = 0; j < jewels.size(); j++) {
            for (auto x : count) {
                if (x.first == jewels[j]) {
                    counts += x.second;
                }
            }
        }
        return counts;
    }
};