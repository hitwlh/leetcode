class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> map1(128, 0), map2(128, 0);
        for(auto i:s1) map1[i-'a']++;
        for(int i = 0; i < s1.length(); i++)
            map2[s2[i]-'a']++;
        for(int i = s1.length(); i < s2.length(); i++){
            if(map1 == map2) return true;
            map2[s2[i-s1.length()] - 'a']--;
            map2[s2[i] - 'a']++;
        }
        return map1 == map2;
    }
};