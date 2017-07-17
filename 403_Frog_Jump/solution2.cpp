class Solution {
public:
    bool canCross(vector<int>& stones) {
        my_stones = stones;
        return dfs(0, 0);
    }
private:
    vector<int> my_stones;
    bool dfs(int pos, int k){
        if(pos + 1 >= my_stones.size()) return true;
        for(int i = 1 + pos; i < my_stones.size(); i++){
            if(my_stones[i] - my_stones[pos] > k + 1) return false;
            if(my_stones[i] - my_stones[pos] < k - 1) continue;
            if(dfs(i, my_stones[i] - my_stones[pos])) return true;
        }
        return false;
    }
};