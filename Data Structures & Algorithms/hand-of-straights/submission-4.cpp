class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> amounts;

        for (int card : hand) {
            amounts[card]++;
        }

        for (auto [card, count] : amounts) {
            if (count == 0) continue;

            for (int x = card; x < card + groupSize; x++) {
                if (amounts[x] < count) return false;
                amounts[x] -= count;
            }
        }

        return true;
    }
};