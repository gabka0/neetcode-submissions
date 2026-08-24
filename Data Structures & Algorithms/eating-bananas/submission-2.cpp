class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        auto max_p = *max_element(piles.begin(), piles.end());
        int max = max_p;
        int ans1 = max;
        while(min<=max){
            int mid = (min+max)/2;
            int ans = 0;
            for(int x: piles){
                ans += (x + mid - 1) / mid;
            }
            if(ans>h){
                min = mid+1;
            }
            else{
                max = mid-1;
                ans1 = mid;
            }
        }
        return ans1;

        
    }
};
