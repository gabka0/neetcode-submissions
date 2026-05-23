class Solution {
public:
    int uniquePaths(int m, int n) {
        int prevrow[n] = {0};
        for(int i=m-1; i>=0; i-=1){
            int currow[n] = {0};
            currow[n-1] = 1;
            for(int j=n-2; j>=0; j-=1){
                currow[j] = currow[j+1] + prevrow[j];
            }
            copy(currow, currow + n, prevrow);
        }
        return prevrow[0];
        
    }
};
