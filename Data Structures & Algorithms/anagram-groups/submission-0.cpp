class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> list;
        vector<vector<string>> ans;
        for(string a: strs){
            string x = a;
            sort(x.begin(), x.end());
            list[x].push_back(a);        
            }
        for(auto x: list){
            ans.push_back(x.second);
        }
        return ans;
    }
    };
