class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() + 1 - k;
        int L = 0, R = nums.size()-1, mid, pivot, i, left, right;
        do{
            left = L, right = R;
            mid = left + (right - left) / 2;
            pivot = nums[mid];
            i = left;
            while(i <= right){
                if(nums[i] < pivot)
                    swap(nums[i++], nums[left++]);
                else if(nums[i] > pivot)
                    swap(nums[i], nums[right--]);
                else
                    i++;
            }
            if(k <= left){
                L = 0;
                R = left - 1;
            }else{
                L = right + 1;
                R = R;
            }
        }while(k <= left || k > right + 1);
        return nums[left];
    }
};