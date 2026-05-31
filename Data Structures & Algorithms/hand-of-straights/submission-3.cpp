class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        vector<int> amounts(1001);
        for(int i=0; i<hand.size();i++){
            amounts[hand[i]]++;
        }
        for(int i=0; i<amounts.size();i++){
            if(amounts[i]==0) continue;
            int count = amounts[i];
            for(int j=i+1; j<i+groupSize;j++){
                if(amounts[j]<count || j>1000 ) return false;
                amounts[j]-=count;
            }
            
        }
        return true;

        
    }
};
