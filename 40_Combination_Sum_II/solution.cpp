class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        my_candidates = candidates;
        size = candidates.size();
        sort(my_candidates.begin(), my_candidates.end());
        vector<int> nul;
        my_com(nul, 0, target, 0);
        return ret;
    }
private:
    vector<int> my_candidates;
    int size;
    vector<vector<int>> ret;
    void my_com(vector<int> &tmp, int start, int target, int segment_start){
        if(start >= size) return;
        for(int i = start; i < size; i++){
            if(segment_start>0 && my_candidates[start] == my_candidates[start-1] && start != segment_start) continue; 
            if(my_candidates[i] < target){
                vector<int> add = tmp;
                add.push_back(my_candidates[i]);
                if(i > 0 && my_candidates[i] != my_candidates[i-1]) segment_start++;
                my_com(add, i+1, target-my_candidates[i], segment_start);
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