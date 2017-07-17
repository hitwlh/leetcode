class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder == "#") return true;//
        vector<int> record;
        bool flag = true;
        for(int i = 0; i < preorder.length(); i++){
            if(preorder[i] == '#') record.push_back(0);
            else if(preorder[i] == ',') flag = true;
            else if(flag){
                flag = false;
                record.push_back(1);
            }
        }
        int diff = 1;
        for(auto i: record){
            if(--diff < 0) return false;
            if(i == 1) diff += 2;
        }
        return diff == 0;
    }
};