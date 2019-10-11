class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> usable;
        int level = 0;
        for(auto i: wordList)
            usable[i] = true;
        queue<string> myque;
        myque.push(beginWord);
        usable[beginWord] = false;
        myque.push("-1");
        while(!myque.empty()){
            string front = myque.front();
            myque.pop();
            if(front == "-1"){
                if(myque.empty()) return 0;
                else myque.push("-1");
                level++;
            }else{
                if(front == endWord) return level+1;
                for(int i = 0; i < front.length(); i++){
                    char x = front[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        front[i] = c;
                        if(usable[front]){
                            myque.push(front);
                            usable[front] = false;
                        }
                    }
                    front[i] = x;
                }
            }
        }
        return 0;
    }
};