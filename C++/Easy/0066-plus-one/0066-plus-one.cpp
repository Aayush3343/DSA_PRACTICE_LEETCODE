class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        while (n > 0) {
            if (digits[n - 1] < 9) {
                digits[n - 1]++;
                break;
            } else {
                digits[n - 1] = 0;
                n--;
            }
        }
        if (n == 0) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};