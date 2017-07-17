class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> num(envelopes.size(), 1);
        for(int i = 1; i < envelopes.size(); i++){
            int MAX = 0;
            for(int j = i-1; j >= 0; j--)
                if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
                    MAX = max(MAX, num[j]);
            num[i] += MAX;
        }
        //return num[num.size()-1];
        int MAX = 0;
        for(int i = 0; i < num.size(); i++)
            MAX = max(num[i], MAX);
        return MAX;
    }
};