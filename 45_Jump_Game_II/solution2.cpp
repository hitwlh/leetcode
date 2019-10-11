class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, ret = 0, place = 0, size = nums.size();
        if(size<=1) return 0;
        while(i < size){
            int old_place = place;
            for(; i <= min(old_place, size-1); i++)
                place = max(place, nums[i]+i);
            ret++;
            if(place + 1 >= size) break;
        }
        return ret;
    }
};