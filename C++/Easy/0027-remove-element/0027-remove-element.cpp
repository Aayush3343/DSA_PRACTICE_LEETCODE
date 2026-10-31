class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       erase(nums,val);
       int n = nums.size();
       return n;    
    }
};