class Solution {
public:
    vector<int> partitionLabels(string s) {
        int l = 0;
        int r = 0;
        vector<int> last_appearance(26);
        vector<int> ans;
        for(int i=0; i<s.size();i++){
            last_appearance[s[i]-'a'] = i;
        }
        int initial_l = 0;
        while(l<s.size()){
            r = max(r, last_appearance[s[l]-'a']);
            if(l==r){
                ans.push_back(r-initial_l+1);
                initial_l = l+1;
            }
            l++;

            
        }
        return ans;
    }
};
