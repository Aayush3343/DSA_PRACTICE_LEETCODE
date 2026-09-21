#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Finds the previous strictly smaller index for every element.
    vector<int> findPreviousLess(vector<int>& arr) {
        int n = arr.size();
        vector<int> previousLess(n, -1);
        stack<int> indices;

        // Scan from left to right for previous boundaries.
        for (int i = 0; i < n; i++) {
            // Remove values that are not strictly smaller.
            while (!indices.empty() &&
                   arr[indices.top()] >= arr[i]) {
                indices.pop();
            }

            // A remaining index is the previous smaller boundary.
            if (!indices.empty()) {
                previousLess[i] = indices.top();
            }

            // Save the current index for later elements.
            indices.push(i);
        }

        return previousLess;
    }

    // Finds the next smaller-or-equal index for every element.
    vector<int> findNextLessOrEqual(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextLessOrEqual(n, n);
        stack<int> indices;

        // Scan from right to left for next boundaries.
        for (int i = n - 1; i >= 0; i--) {
            // Remove values that are strictly greater.
            while (!indices.empty() &&
                   arr[indices.top()] > arr[i]) {
                indices.pop();
            }

            // A remaining index is the next valid boundary.
            if (!indices.empty()) {
                nextLessOrEqual[i] = indices.top();
            }

            // Save the current index for earlier elements.
            indices.push(i);
        }

        return nextLessOrEqual;
    }

public:
    // Returns the sum of all subarray minimums.
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long mod = 1000000007;

        vector<int> previousLess = findPreviousLess(arr);
        vector<int> nextLessOrEqual = findNextLessOrEqual(arr);

        long long answer = 0;

        // Calculate each element's contribution as the minimum.
        for (int i = 0; i < n; i++) {
            long long leftChoices = i - previousLess[i];
            long long rightChoices = nextLessOrEqual[i] - i;

            // Count all subarrays where arr[i] owns the minimum.
            long long contribution =
                (arr[i] * leftChoices) % mod;
            contribution =
                (contribution * rightChoices) % mod;

            // Add the current contribution to the answer.
            answer = (answer + contribution) % mod;
        }

        return (int)answer;
    }
};