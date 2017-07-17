class Solution {
public:
    int countArrangement(int N) {
        for(int i = 1; i <= N; i++)
            nums.push_back(i);
        n = N;
        perm(0);
        return ret;
    }
private:
    int ret = 0, n;
    vector<int> nums;
    void perm(int level){
        if(level >= n){
            ret++;
            return;
        }
        for(int i = level; i < n; i++){
            swap(nums[i], nums[level]);
            if(nums[level] % (level+1) == 0 || (level+1) % nums[level] == 0){
                perm(level+1);
            }
            swap(nums[i], nums[level]);
        }
    }
};