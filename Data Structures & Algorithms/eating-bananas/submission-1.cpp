class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = 0;
        for(int i=0; i<piles.size();i++){
            if(piles[i]>r){
                r = piles[i];
            }
        }
        int l = 1;
        while(l<r){
            int mid = l+(r-l)/2;
            int temp = 0;
            for(int i=0; i<piles.size();i++){
                temp+=(piles[i]+mid-1)/mid;
            }
            if(temp>h){
                l = mid+1;
            }
            else if(temp<=h){
                r = mid;
            }
        }
        return l;
    }
};
