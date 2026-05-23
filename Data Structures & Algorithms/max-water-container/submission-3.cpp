 #include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int first = 0;
        int second = heights.size()-1;
        int maxim = 0;
        while(first!=second){
            int minim = min(heights[first], heights[second]);
            int length = second - first;
            int area = length * minim;
            maxim = max(maxim, area);
            if(heights[first]<=heights[second]){
                first++;
            }
            else{
                second--;
            }

        }
        return maxim; 
    }
};
