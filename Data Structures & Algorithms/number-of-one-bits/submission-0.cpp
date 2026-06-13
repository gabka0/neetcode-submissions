class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        for (int i = 0; i < 32; i++) {
            uint32_t j = 1u << i;

            if ((j & n) != 0) {
                count++;
            }
        }

        return count;
    }
};
