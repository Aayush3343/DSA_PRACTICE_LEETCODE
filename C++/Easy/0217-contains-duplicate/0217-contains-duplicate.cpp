class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> counts;
        for (int i = 0; i < n; i++) {
            counts[nums[i]]++;
        }
        for (auto x : counts) {
            if (x.second >= 2) {
                return true;
            }
        }
        return false;
    }
};