class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() <= 1) return false;
        int n = nums.size();
        vector<int> sum(n, 0);
        unordered_map<int, int> mymap;
        sum[0] = nums[0];
        for(int i = 1; i < n; i++)
            sum[i] = sum[i-1] + nums[i];
        for(int i = 0; i < n; i++){
            int t = (k == 0) ? sum[i] : (sum[i] % k);
            if(t == 0 && i > 0) return true;
            if(mymap.find(t) != mymap.end() && mymap[t] < i-1) return true;
            mymap[t] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() <= 1) return false;
        int n = nums.size(), sum = 0;
        unordered_map<int, int> mymap;
        mymap[0] = -1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if(mymap.find(t) == mymap.end())
                mymap[t] = i;
            else if(mymap[t] < i-1) return true;
            //else return true;
        }
        return false;
    }
};