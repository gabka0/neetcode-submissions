class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int maxLen = 1;
        int left = 0;

        for (int right = 1; right < n; ++right) {
            int cmp = compare(arr[right - 1], arr[right]);
            if (cmp == 0) {
                left = right;
            } else if (right == n - 1 || cmp * compare(arr[right], arr[right + 1]) != -1) {
                maxLen = max(maxLen, right - left + 1);
                left = right;
            }
        }

        return maxLen;
    }

private:
    // Helper function to return sign of difference
    int compare(int a, int b) {
        return (a > b) ? 1 : (a < b) ? -1 : 0;
    }
};