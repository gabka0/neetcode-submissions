class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stck;
        vector<int> ans (temperatures.size(), 0);
        for(int i=temperatures.size()-1; i>=0; i--){
                while(!stck.empty() && temperatures[i]>=stck.top().first){
                    stck.pop();
                }
                if(stck.empty()) ans[i] = 0;
                else{
                    ans[i] = stck.top().second - i;
                }
                stck.push({temperatures[i],i});
            }
        return ans;
    }
    };
