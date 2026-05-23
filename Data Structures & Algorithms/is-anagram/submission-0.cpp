#include <iostream>
#include <set>
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> str1; 
        unordered_map<char, int> str2; 
        for(char a: s){
            str1[a]++;
        }
        for(char a: t){
            str2[a]++;
        }
        return str1==str2;
    }
};
