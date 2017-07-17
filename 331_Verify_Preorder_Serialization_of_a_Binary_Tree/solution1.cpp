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
        stack<int> sta1;
        for(int i = 0; i < record.size(); i++){
            if(record[i] == 1) sta1.push(1);
            else sta1.push(0);
            while(sta1.top() == 0){
                sta1.pop();
                if(!sta1.empty() && sta1.top() == 0){
                    sta1.pop();
                    if(sta1.empty()) return false;
                    sta1.pop();
                    sta1.push(0);
                }
                else{
                    sta1.push(0);
                    break;
                }
            }
        }
        return sta1.size() == 1 && sta1.top() == 0;
    }
};