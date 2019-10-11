class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ret = INT_MIN;
        for(auto i: houses){
            int left = 0, right = heaters.size()-1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(heaters[mid] >= i) right = mid-1;
                else left = mid+1;
            }
            int MIN = INT_MAX;
            if(right + 1 < heaters.size())
                MIN = min(MIN, heaters[right+1] - i);
            if(right >= 0)
                MIN = min(MIN, i - heaters[right]);
            ret = max(MIN, ret);
        }
        return ret;
    }
};