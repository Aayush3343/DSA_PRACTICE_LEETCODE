class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() < abs(asteroids[i]) &&
                       st.top() > 0) {
                    st.pop();
                }
                if (st.empty()) {
                    st.push(asteroids[i]);
                } else {
                    if (st.top() > abs(asteroids[i])) {
                        continue;
                    } else if (st.top() == abs(asteroids[i])) {
                        st.pop();
                    }
                    else{
                        st.push(asteroids[i]);
                    }
                }
            }
        }
    
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};