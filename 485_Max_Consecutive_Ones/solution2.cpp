class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> times;
        for(auto i: nums)
            times[i]++;
        int ret = 0;
        for(auto number: times)
            if(k == 0 and number.second > 1) ret++;
            else if(k > 0 and times.count(number.first+k)) ret++;
        return ret;
    }
};