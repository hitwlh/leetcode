class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> pos;
        vector<int> ret;
        if(S.length() <= 0) return ret;
        for(int i = S.length()-1; i >= 0; i--)
            if(not pos.count(S[i])) pos[S[i]] = i;
        int i = 0, right, old_right;
        while(i < S.length()){
            right = pos[S[i]];
            if(right == i){
                ret.push_back(1);
                i++;
            }else{
                for(int j = i + 1; j < right; j++)
                    right = max(right, pos[S[j]]);
                ret.push_back(right - i + 1);
                i = right+1;
            }
        }
        return ret;
    }
};