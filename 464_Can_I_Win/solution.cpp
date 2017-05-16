class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        if(maxChoosableInteger * (maxChoosableInteger+1) < desiredTotal * 2) return false;
        unsigned int use = 0;
        return dfs(maxChoosableInteger, desiredTotal, use);
    }
private:
    bool dfs(int size, int sum, unsigned int mmp){
        if(tmp_result.find(mmp) != tmp_result.end())
            return tmp_result[mmp];
        for(int i = 1; i <= size; i++){
            unsigned int choose = 1 << (i-1);
            if((choose & mmp) == 0){
                if(i >= sum || (!dfs(size, sum - i, mmp | choose))){
                    tmp_result[mmp] = true;
                    return true;
                }
            }
        }
        tmp_result[mmp] = false;
        return false;
    }
    unordered_map<unsigned int, bool> tmp_result;
};