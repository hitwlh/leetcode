class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        vector<int> left(n, INT_MAX);
        for(int i = 1; i < n; i++)
            left[i] = min(left[i-1], nums[i-1]);
        set<int> right;
        right.insert(nums[n-1]);
        for(int i = n-2; i >0; i--){
            int one = left[i], three = nums[i];
            auto it = right.upper_bound(one);
            if(it != right.end() && *it < three) return true;
            right.insert(nums[i]);
        }
        return false;
    }
};