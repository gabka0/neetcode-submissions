class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int> count1(26, 0);
        vector<int> count2(26,0);
        for(int i=0; i<s1.length();i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        int first = 0;
        int second = s1.length()-1;
        while(second<s2.length()){
            if(count1==count2) return true;
            count2[s2[first]-'a']--;
            second++;
            count2[s2[second]-'a']++;
            first++;
        }
        return false;
        

    }
};
