class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<int> prev(cols, 0);

        // Initialize the last cell
        if (obstacleGrid[rows-1][cols-1] == 0)
            prev[cols - 1] = 1;

        for (int i = rows - 1; i >= 0; i--) {
            vector<int> curr(cols, 0);
            for (int j = cols - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else if (i == rows - 1 && j == cols - 1) {
                    curr[j] = prev[j]; // Already initialized
                } else {
                    int right = (j + 1 < cols) ? curr[j + 1] : 0;
                    int down = prev[j];
                    curr[j] = right + down;
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};

