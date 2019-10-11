class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> set1, set2;
        for(auto i: nums1) set1[i]++;
        for(auto i: nums2) set2[i]++;
        vector<int> ret;
        for(auto i: set1){
            if(set2.count(i.first))
                ret.push_back(i.first);
        }
        return ret;
    }
};