bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty())
            return 0;
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> gr(envelopes.size(), 0);
        int len = 0;
        gr[len++] = envelopes[0].second;
        for(int i = 1; i < envelopes.size(); i++){
            if(envelopes[i].second < gr[0]) gr[0] = envelopes[i].second;
            else if(envelopes[i].second > gr[len-1]) gr[len++] = envelopes[i].second;
            else{
                int it = find(gr, len, envelopes[i].second);
                gr[it] = envelopes[i].second;
            }
        }
        return len;
    }
private:
    int find(vector<int> &gr, int len, int target){
        int left = 0, right = len - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(gr[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;//返回第一个>=target的
    }
};