class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1) return;
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        int midVal = nums[nums.size()/2];
        int odd = 1, even = 0, left = 1, right = nums.size();
        if(right % 2) right -= 1;
        else right -= 2;
        for(int i = odd; i < nums.size(); i += 2){
            if(nums[i] < midVal){
                swap(nums[i], nums[right]);
                right -= 2;
                i -= 2;
            }
            else if(nums[i] > midVal){
                swap(nums[i], nums[left]);
                left += 2;
            }
        }
        for(int i = even; i <= right; i += 2){
            if(nums[i] < midVal){
                swap(nums[i], nums[right]);
                right -= 2;
                i -= 2;
            }
            else if(nums[i] > midVal){
                swap(nums[i], nums[left]);
                left += 2;
            }
        }
    }
};







class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        size = nums.size();
        if(nums.size() <= 1) return;
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        int midVal = nums[nums.size()/2], i = 0, j = nums.size()-1, now = 0;
        while(now <= j){
            if(nums[indexMap(now)] < midVal){
                swap(nums[indexMap(j)], nums[indexMap(now)]);
                j--;
            }else if(nums[indexMap(now)] > midVal){
                swap(nums[indexMap(i)], nums[indexMap(now)]);
                i++;
                now++;
            }else{
                now++;
            }
        }
    }
private:
    int size;
    int indexMap(int index){
        return (1+2*index) % (size | 1);
    }
};
