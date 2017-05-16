class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int MAX = INT_MIN;
        sort(heaters.begin(), heaters.end());
        for(int i = 0; i < houses.size(); i++)
            MAX = max(MAX, needRadius(heaters, houses[i]));
        return MAX;
    }
private:
    int needRadius(vector<int>& heaters, int house){
        int left = 0, right = heaters.size()-1;
        int ret = INT_MAX;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(heaters[mid] == house) return 0;
            ret = min(ret, abs(heaters[mid] - house));
            if(heaters[mid] > house)
                right = mid - 1;
            else
                left = mid+1;
        }
        ret = min(ret, abs(house - heaters[left]));
        return ret;
    }
};