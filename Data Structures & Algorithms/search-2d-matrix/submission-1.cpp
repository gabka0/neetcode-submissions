class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        if(target<matrix[0][0] || target>matrix[matrix.size()-1][matrix[0].size()-1]){
            return false;
        }
        int range = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target<matrix[mid][0]){
                high = mid-1;
            }
            else if(target>matrix[mid][matrix[0].size()-1]){
                low = mid+1;
            }
            else{
                range = mid;
                break;
            }
        }
        vector<int>& matrix2 = matrix[range];
        low = 0;
        high = matrix2.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target<matrix2[mid]){
                high = mid-1;
            }
            else if(target>matrix2[mid]){
                low = mid+1;
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};
