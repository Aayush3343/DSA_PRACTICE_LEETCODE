class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> save;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                save.push(asteroids[i]);
            } else {
                while (!save.empty() && save.top() < abs(asteroids[i]) &&
                       save.top() > 0) {
                    save.pop();
                }
                if (save.empty()) {
                    save.push(asteroids[i]);
                }
                else
                {
                if (save.top() > abs(asteroids[i])) {
                    continue;
                }
                if (save.top() == abs(asteroids[i])) {
                    save.pop();
                    continue;
                }
                if (save.top() < 0) {
                    save.push(asteroids[i]);
                }
                }
            }
        }
        vector<int> ans;
        while (!save.empty()) {
            ans.push_back(save.top());
            save.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};