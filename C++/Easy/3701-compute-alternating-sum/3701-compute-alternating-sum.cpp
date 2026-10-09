class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int eSum = 0;
        int oSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                eSum += nums[i];
            } else {
                oSum += nums[i];
            }
        }
        return eSum - oSum;
    }
};