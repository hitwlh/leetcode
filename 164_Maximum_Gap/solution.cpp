class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int size = nums.size(), MIN = INT_MAX, MAX = INT_MIN;
        for(auto i: nums){
            MIN = min(i, MIN);
            MAX = max(i, MAX);
        }
        int len = (MAX - MIN) / size;
        if(len == 0) len++;
        vector<int> bucket;
        vector<vector<int>> buckets((MAX-MIN)/len + 3, bucket);
        for(int i = 0; i < nums.size(); i++)
            buckets[(nums[i] - MIN)/ len].push_back(nums[i]);
        int ret = 0, old_MAX;
        for(int i = 0; i < buckets.size(); i++){
            MIN = INT_MAX, MAX = INT_MIN;
            bool flag = false;
            for(int j = 0; j < buckets[i].size(); j++){
                MAX = max(MAX, buckets[i][j]);
                MIN = min(MIN, buckets[i][j]);
                flag = true;
            }
            if(flag){
                if(i > 0)
                    ret = max(ret, MIN - old_MAX);
                old_MAX = MAX;
            }
        }
        return ret;
    }
};