class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        my_candidates = candidates;
        size = candidates.size();
        sort(my_candidates.begin(), my_candidates.end());
        vector<int> nul;
        my_com(nul, 0, target);
        return ret;
    }
private:
    vector<int> my_candidates;
    int size;
    vector<vector<int>> ret;
    void my_com(vector<int> &tmp, int start, int target){
        for(int i = start; i < size; i++){
            if(my_candidates[i] < target){
                vector<int> add = tmp;
                add.push_back(my_candidates[i]);
                my_com(add, i, target-my_candidates[i]);
            }else if(my_candidates[i] == target){
                tmp.push_back(my_candidates[i]);
                ret.push_back(tmp);
                break;
            }else{
                break;
            };
        }
    }
    
};