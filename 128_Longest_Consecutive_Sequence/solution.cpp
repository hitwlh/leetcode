class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> myset;
        for(int i = 0; i < nums.size(); i++)
            myset.insert(nums[i]);
        int ret = 0, MAX = 0;
        for(int i = 0; i < nums.size(); i++){
            int up = nums[i] + 1, down = nums[i] - 1;
            ret = 1;
            myset.erase(nums[i]);
            while(myset.find(up) != myset.end()){
                myset.erase(up);
                up++;
                ret++;
            }
            while(myset.find(down) != myset.end()){
                myset.erase(down);
                down--;
                ret++;
            }
            if(ret > MAX) MAX = ret;
        }
        return MAX;
    }
};