class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> time(26, 0);
        vector<bool> visited(26, false);
        stack<char> mysta;
        string ret;
        for (int i = 0; i < s.length(); ++i) 
            time[s[i] - 'a']++;
        for(int i = 0; i < s.length(); i++){
            time[s[i] - 'a']--;
            if(visited[s[i] - 'a'] == true)
                continue;   
            visited[s[i] - 'a'] = true;
            while(!mysta.empty() && time[mysta.top() - 'a'] > 0 && s[i] < mysta.top()){
                visited[mysta.top() - 'a'] = false;
                mysta.pop();
            }
            mysta.push(s[i]);
        }
        while(!mysta.empty()){
            ret = mysta.top() + ret;
            mysta.pop();
        }
        return ret;
    }
};