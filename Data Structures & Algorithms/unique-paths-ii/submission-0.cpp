class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int columns = obstacleGrid[0].size();
        int rows = obstacleGrid.size();
        int prevrow[columns] = {0};
        bool firstCheck = true;
        for(int i=rows-1;i>=0;i--){
            int currow[columns] = {0};
            if(firstCheck == true && obstacleGrid[i][columns-1]==0){
                currow[columns-1] = 1;
            }
            else{
                currow[columns-1] = 0;
                firstCheck = false;
            }
            for(int j=columns-2; j>=0; j--){
                if(obstacleGrid[i][j]==0){
                    currow[j] = currow[j+1] + prevrow[j];
                }
                else{
                    currow[j] = 0;
                }
        }
        copy(currow, currow + columns, prevrow);
    }
    return prevrow[0];
}
};