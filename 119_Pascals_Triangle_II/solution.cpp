class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tmp;
        if(rowIndex < 0) return tmp;
        tmp.push_back(1);
        if(rowIndex == 0) return tmp;
        while(tmp.size() - 1 < rowIndex){
            for(int i = tmp.size() - 1; i > 0; i--)
                tmp[i] = tmp[i] + tmp[i-1];
            tmp.push_back(1);
        }
        return tmp;
    }
};