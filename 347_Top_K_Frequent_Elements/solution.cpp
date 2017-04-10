class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(auto i: nums)
            mymap[i]++;
        for(auto x:mymap)
            mypq.push( make_pair(x.second, x.first));
        for(int i=0; i<k; i++){
            ret.push_back(get<1>(mypq.top()));
            mypq.pop();
        }
        return ret;
    }
private:
    unordered_map<int, int> mymap;
    priority_queue<pair<int, int>> mypq;
    vector<int> ret;
};