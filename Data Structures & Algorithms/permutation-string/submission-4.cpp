class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1 (26, 0);
        vector<int> count2 (26, 0);
        if(s1.size()>s2.size()) return false;
        for(int i=0; i<s1.size();i++){
            count1[s1[i]-'a'] += 1;
            count2[s2[i]-'a'] +=1;
        }
        if (count1 == count2) return true;
        int l = 0;
        for(int r=s1.size(); r<s2.size();r++){
            count2[s2[l]-'a']--;
            l++;
            count2[s2[r]-'a']++;
            if(count2==count1) return true;
        }
        return false;
    }
};
