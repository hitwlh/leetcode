class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ret.push_back({});
        if(nums.empty()) return ret;
        dfs(0, nums);
        return ret;
    }
private:
    void dfs(int start, vector<int>& nums){
        if(start+1 == nums.size()){
            ret.push_back({nums[start]});
            return;
        }
        dfs(start+1, nums);
        vector<vector<int>> doubl = ret;
        for(int i = 0; i < doubl.size(); i++)
            doubl[i].push_back(nums[start]);
        ret.insert(ret.end(), doubl.begin(), doubl.end());
    }
    vector<vector<int>> ret;
};