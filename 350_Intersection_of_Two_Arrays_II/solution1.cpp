class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        for(int i=0; i<nums2.size(); i++){
            for(int j=0; j<nums1.size(); j++){
                if(nums2[i] == nums1[j]){
                    ret.push_back(nums1[j]);
                    auto it = nums1.begin()+j;
                    nums1.erase(it);
                    break;
                }
            }
        }
    return ret;
    }
};