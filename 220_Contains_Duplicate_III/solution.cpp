class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> mymap;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > j + k) mymap.erase(nums[j++]);
            auto it = mymap.lower_bound((long long)nums[i] - t);
            if(it != mymap.end() && fabs(nums[i] - it->first) <= t)
                return true;
            mymap[nums[i]] = i;
        }
        return false;
    }
};