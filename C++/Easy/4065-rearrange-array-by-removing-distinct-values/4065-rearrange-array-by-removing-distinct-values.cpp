class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> mpp;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        int maxi = 0;
        for (auto it : mpp) {
            maxi = max(maxi, it.second);
        }

        vector<int> ans;
        for (int i = 0; i < maxi; i++) {
            for (auto &it : mpp) {
                if (it.second > 0) {
                    ans.push_back(it.first);
                    it.second--;
                }
            }
        }
        return ans;
    }
};