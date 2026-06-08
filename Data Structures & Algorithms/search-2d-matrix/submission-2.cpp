class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid, mid2;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows-1;
        while(low<=high){
            mid = (low+high)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][cols-1]){
                break;
            }
            else if(target>matrix[mid][cols-1]){
                low = mid+1;
            }
            else if(target<matrix[mid][0]){
                high = mid-1;
            }
        }
        low = 0;
        high = cols-1;
        while(low<=high){
            mid2 = (low+high)/2;
            if(target==matrix[mid][mid2]) return true;
            else if(target>matrix[mid][mid2]) low = mid2+1;
            else if(target<matrix[mid][mid2]) high = mid2-1;
        }
        return false;
    }
};
