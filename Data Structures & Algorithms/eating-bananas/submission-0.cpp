class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for(int& k:piles){
            if(k>max) max = k;
        }
        int min = 1;
        while(min<=max){
            int mid = (max + min) / 2;
            int hours = 0;
            for(int& x: piles){
                hours += (x + mid - 1) / mid;
            }
            if(hours<=h){
                max = mid-1;
            }
            else{
                min = mid+1;
            }
        }
        return min;
        
        
    }
};