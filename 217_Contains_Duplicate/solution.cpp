class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mymap;
        for(auto i: nums){
            if(mymap.find(i) != mymap.end()) return true;
            mymap[i] = true;
        }
        return false;
    }
};