class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ret.push_back({});
        if(nums.empty()) return ret;
        quantile = 0;
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return ret;
    }
private:
    int quantile;
    void dfs(int start, vector<int>& nums){
        if(start+1 == nums.size()){
            ret.push_back({nums[start]});
            return;
        }
        dfs(start+1, nums);
        vector<vector<int>> doubl;
        if(nums[start] == nums[start+1]){
            quantile++;
            doubl.assign(ret.begin() +quantile*(ret.size())/(quantile+1), ret.end());
        }
        else{
            quantile = 0;
            doubl.assign(ret.begin(), ret.end());
        }
        for(int i = 0; i < doubl.size(); i++)
            doubl[i].push_back(nums[start]);
        ret.insert(ret.end(), doubl.begin(), doubl.end());
    }
    vector<vector<int>> ret;
};