class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        vector<int> ans;
        for (int x : nums) {
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        for (int x : nums) {

            if (x != mini && x != maxi) {
                ans.push_back(x);
            }
        }
        return ans.size();
    }
};