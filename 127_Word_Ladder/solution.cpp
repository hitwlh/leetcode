class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> mymap;
        for(auto i: wordList) mymap[i] = true;
        queue<string> que[2];
        que[0].push(beginWord);
        int ret = 0, uq = 0,flag = 0;
        while(!que[uq].empty()){
            string fron = que[uq].front();
            if(fron == endWord){
                flag = 1;
                break;
            }
            que[uq].pop();
            /*for(int i = 0; i < wordList.size(); i++){
                if(equa(wordList[i], fron)){
                    que[1-uq].push(wordList[i]);
                    wordList.erase(wordList.begin() + i);
                    i--;
                }
            }*/
            for(int i = 0; i < fron.size(); i++){
                char m = fron[i];
                for(int j = 0; j < 26; j++){
                    if(j != m - 'a'){
                        fron[i] = 'a' + j;
                        if(mymap.find(fron) != mymap.end() && mymap[fron] == true){
                            mymap[fron] = false;
                            que[1-uq].push(fron);
                        }
                    }
                }
                fron[i] = m;
            }
            if(que[uq].empty()){
                uq = 1-uq;
                ret++;
            }
        }
        return flag == 1 ? ret + 1 : 0;
    }
private:
    bool equa(string s1, string s2){
        if(s1.length() != s2.length()) return false;
        int flag = 0;
        for(int i  = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]){
                if(flag) return false;
                flag++;
            }
        }
        return flag == 1;
    }
};