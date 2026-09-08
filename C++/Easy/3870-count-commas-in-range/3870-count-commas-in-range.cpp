class Solution {
public:
    int countCommas(int n) {
        int comma = 0;
        int i = 1000;
        while (i <= n) {
            comma++;
            i++;
        }
        return comma;
    }
};