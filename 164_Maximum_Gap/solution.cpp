class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int MIN = INT_MAX, MAX = INT_MIN, n = nums.size();
        for(auto i: nums){
            MIN = min(i, MIN);
            MAX = max(i, MAX);
        }
        int len = ceil(((double)(MAX - MIN)) / (n - 1));
        if(len == 0) return 0;
        vector<int> tmp;
        vector<vector<int>> bucket((MAX - MIN) / len + 1, tmp);
        for(auto i :nums)
            bucket[(i-MIN) / len].push_back(i);
        int ret = INT_MIN;
        vector<int> mAX, mIN;
        for(int i = 0; i + 1< bucket.size(); i++){
            MAX = INT_MIN;
            bool fmax = false;
            for(int j = 0; j < bucket[i].size(); j++){
                MAX = max(MAX, bucket[i][j]);
                fmax = true;
            }
            if(fmax) mAX.push_back(MAX);
        }
        for(int i = 1; i < bucket.size(); i++){
            MIN = INT_MAX;
            bool fmin = false;
            for(int j = 0; j < bucket[i].size(); j++){
                MIN = min(MIN, bucket[i][j]);
                fmin = true;
            }
            if(fmin) mIN.push_back(MIN);
        }
        if(mIN.size() < mAX.size()) mIN.push_back(mAX.back());
        else if(mIN.size() > mAX.size()) mAX.insert(mAX.begin(), mIN[0]);
        for(int i = 0; i < mIN.size(); i++)
            ret = max(mIN[i] - mAX[i], ret);
        return ret;
    }
};