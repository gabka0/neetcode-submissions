class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        int width = matrix[0].size();
        int min = 0;
        int max = height-1;
        int mid;
        if(target<matrix[0][0] || target>matrix[height-1][width-1]) return false;

        while(min<=max){
            mid = (min+max)/2;
            if(matrix[mid][0]<=target && matrix[mid][width-1]>=target){
                break;
            }
            else if(matrix[mid][0]>target){
                max = mid - 1;
            }
            else{
                min = mid+1;
            }
        }
        min = 0;
        max = width - 1;
        while(min<=max){
            int mid1 = (min+max)/2;
            if(matrix[mid][mid1]>target){
                max = mid1-1;
            }
            else if(matrix[mid][mid1]<target){
                min = mid1 + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
