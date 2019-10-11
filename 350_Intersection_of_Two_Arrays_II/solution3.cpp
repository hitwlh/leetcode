class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> set1, set2;
        for(auto i: nums1) set1[i]++;
        for(auto i: nums2) set2[i]++;
        vector<int> ret;
        for(auto i: set1){
            for(int j = 0; j < min(i.second, set2[i.first]); j++)
                ret.push_back(i.first);
        }
        return ret;
    }
};