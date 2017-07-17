class Solution {
public:
    int countArrangement(int N) {
        for(int i = 1; i <= N; i++)
            nums.push_back(i);
        n = N;
        perm(N);
        return ret;
    }
private:
    int ret = 0, n;
    vector<int> nums;
    void perm(int level){
        //for(int i = 0; i < n; i++) cout << nums[i] << ' ' ;
        //cout << endl;
        if(level <= 0){
            ret++;
            return;
        }
        for(int i = 0; i < level; i++){
            if(nums[i] % level == 0 || level % nums[i] == 0){
                //cout << "success" << "(" << level << ", " << nums[i] << ")\n";
                swap(nums[i], nums[level-1]);
                perm(level-1);
                swap(nums[i], nums[level-1]);
            }
        }
    }
};