class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int MAX = INT_MIN;
        for(auto i: citations) MAX = max(MAX, i);
        map<int, int> jilu;
        for(auto i: citations) jilu[i]++;
        int sum = 0;
        for(int i = MAX; i>=0; i--){
            sum += jilu[i];
            if(sum >= i) return i;
        }
        return 0;
    }
};