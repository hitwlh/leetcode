class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        //对所给序列排序
        sort(citations.begin(), citations.end());
        int len = citations.size(), maxH = 0;
        for (int i = len - 1; i >= 0; --i){
            int h = len - i;
            if (citations[i] >= h)
                maxH = h;
            else
                break;
        }//for
        return maxH;
    }
};



class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty() || accumulate(citations.begin(), citations.end(), 0) == 0) return 0;
        sort(citations.begin(), citations.end());
        for(int i = citations.size() - 1; i >= 0; i--){
            int num = citations.size() - i;
            if(citations[i] <= num)
                return citations[i];
        }
        return citations.size();
    }
};
