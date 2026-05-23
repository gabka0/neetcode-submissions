class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long sum = 0;
        int L = 0, count = 0;
        long long need = k * threshold;

        for (int R = 0; R < (int)arr.size(); ++R) {
            sum += arr[R];

            if (R - L + 1 > k) {
                sum -= arr[L++];
            }

            if (R - L + 1 == k) {
                if (sum >= need) ++count;
            }
        }
        return count;
    }
};
