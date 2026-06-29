class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> x;
        for(int i=0; i<points.size();i++){
            int d = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            x.push({d, points[i]});
            if(x.size()>k){
                x.pop();
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<k;i++){
            ans.push_back(x.top().second);
            x.pop();
        }
        return ans;
    }
};
