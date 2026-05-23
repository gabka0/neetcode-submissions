class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int,int>> stck;

        for(int i = 0; i < temperatures.size(); i++){

            if(stck.empty() || stck.top().first >= temperatures[i]) {
                stck.push({temperatures[i], i});
            }
            else{
                while(!stck.empty() && temperatures[i] > stck.top().first){
                    pair<int,int> temp = stck.top();
                    stck.pop();
                    ans[temp.second] = i - temp.second;
                }
                stck.push({temperatures[i], i});
            }

        }
        return ans;
    }
};
