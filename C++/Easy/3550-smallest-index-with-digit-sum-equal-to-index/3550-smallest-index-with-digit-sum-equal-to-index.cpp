class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 10) {
                if (i == nums[i]) {
                    return nums[i];
                }
            } else {
                int sum = 0;
                int x = nums[i];
                while (x > 0) {
                    sum += x % 10;
                    x = x / 10;
                }
                if (sum == i) {
                    return i;
                }
            }
        }
        return -1;
    }
};