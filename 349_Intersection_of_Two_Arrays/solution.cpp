class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it = unique(nums1.begin(), nums1.end());
        nums1.resize(distance(nums1.begin(),it));
        it = unique(nums2.begin(), nums2.end());
        nums2.resize(distance(nums2.begin(),it));
        int flag = 0;
        for(int i=0; i<nums2.size(); i++){
            for(int j=flag; j<nums1.size(); j++){
                if(nums2[i] == nums1[j]){
                    ret.push_back(nums2[i]);
                    flag = j + 1;
                    break;
                }
                else if(nums2[i] > nums1[j])
                    flag = j + 1;
                else if(nums2[i] < nums1[j])
                    break;
            }
        }
    return ret;
    }
};