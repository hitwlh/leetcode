typedef struct mys{
    int score;
    int index;
    mys(int score2, int index2){
        score = score2;
        index = index2;
    }
}my;
bool comp(my s1, my s2){
    return s1.score > s2.score;
}
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<my> data;
        for(int i = 0; i < nums.size(); i++)
            data.push_back(my(nums[i], i));
        sort(data.begin(), data.end(), comp);
        vector<string> ret;
        ret.assign(nums.size(), "");
        for(int i = 0; i < data.size(); i++){
            if(i==0) ret[data[0].index] = "Gold Medal";
            else if(i==1) ret[data[1].index] = "Silver Medal";
            else if(i==2) ret[data[2].index] = "Bronze Medal";
            else{
                stringstream ss;
                ss << i+1;
                ret[data[i].index] = ss.str();
            }
        }
        
        return ret;
    }
};