class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        search(nums, target, 0, nums.size()-1);
        return {ret_left, ret_right};
    }
private:
    int ret_left = INT_MAX, ret_right = -1;
    void search(vector<int>& nums, int target, int left, int right) {
        //cout << "left is: " << left << ", right is: " << right << endl;
        if(right < left) return ;
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            if(mid > ret_right) ret_right = mid;
            if(mid < ret_left) ret_left = mid;
            search(nums, target, mid+1, right);
            search(nums, target, left, mid-1);
        }
        else if(nums[mid] < target) search(nums, target, mid+1, right);
        else search(nums, target, left, mid-1);
        if(ret_right == -1) ret_left = -1;
        //cout << "[" << left << "," << right << "]\n";
    }
};