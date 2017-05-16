class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mymap;
        for(auto c: magazine) mymap[c]++;
        for(auto c: ransomNote) 
            if(mymap[c] > 0) mymap[c]--;
            else return false;
        return true;
    }
};