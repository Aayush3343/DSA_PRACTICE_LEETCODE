class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            mini = nums[i];
            maxi = nums[i];
            for (int j = i; j < n; j++) {
                if (nums[j] < mini) {
                    mini = min(mini, nums[j]);
                }
                if (nums[j] > maxi) {
                    maxi = max(maxi, nums[j]);
                }
                sum += maxi - mini;
            }
        }
        return sum;
    }
};
