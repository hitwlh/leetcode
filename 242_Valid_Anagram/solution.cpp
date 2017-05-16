class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mymap1, mymap2;
        for(auto c: s) mymap1[c]++;
        for(auto c: t) mymap2[c]++;
        return mymap1 == mymap2;
    }
};