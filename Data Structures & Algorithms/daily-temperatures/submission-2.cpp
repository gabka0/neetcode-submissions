class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stck;
        vector<int> ans (temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++){
            while(!stck.empty() && temperatures[i]>stck.top().first ){
                ans[stck.top().second] = i - stck.top().second;
                stck.pop();
            }
            stck.push({temperatures[i],i});
        }
        return ans; 
        
    }
};
