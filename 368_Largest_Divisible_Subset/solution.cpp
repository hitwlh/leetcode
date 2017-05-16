class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        vector<int> path, num, ret;
        path.push_back(-1);
        num.push_back(0);
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            int MAX = -2, MAX_INDEX = i;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && path[j] > MAX){
                    MAX = path[j];
                    MAX_INDEX = j;
                }
            }
            path.push_back(MAX+1);
            num.push_back(MAX_INDEX);
        }
        int MAX = INT_MIN, MAX_INDEX;
        for(int i = 0; i < path.size(); i++)
            if(path[i] > MAX){
                MAX = path[i];
                MAX_INDEX = i;
            }
        int now = MAX_INDEX;
        while(num[now] != now){
            ret.insert(ret.begin(), nums[now]);
            now = num[now];
        }
        ret.insert(ret.begin(), nums[now]);
        return ret;
    }
};