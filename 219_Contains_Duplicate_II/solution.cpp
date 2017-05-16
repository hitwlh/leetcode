class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i = 0; i < nums.size(); i++){
            if(mymap.find(nums[i]) != mymap.end()){
                if(fabs(i - mymap[nums[i]]) <= k)
                    return true;
                else
                    mymap[nums[i]] = i;
            }
            else
                mymap[nums[i]] = i;
        }
        return false;
    }
};