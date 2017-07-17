class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int val;
        for(int i = 0; i < nums.size(); i++){
            val = nums[i];
            while(true){
                //debug(nums);
                if(i+1 == val || val < 0) break;
                if(val == nums[val-1]){
                    ret.push_back(val);
                    nums[i] = -1;
                    break;
                }
                swap(nums[val-1], nums[i]);
                val = nums[i];
            }
        }
        return ret;
    }
private:
    void debug(vector<int>& nums){
        for(int i = 0; i < nums.size(); i++)
            cout << nums[i] << " ";
        cout << endl;
    }
};