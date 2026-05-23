class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        priority_queue<pair<int, vector<int>>> max_heap;
        for(vector<int>& x: points){
            int l = x[0]*x[0]+x[1]*x[1];
            max_heap.push({l, x});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        vector<vector<int>> ans;
        while(!max_heap.empty()){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return ans;
        
    }
};
