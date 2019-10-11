class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in(numCourses, 0), ret;
        vector<vector<int>> out(numCourses, vector<int>());
        for(auto i: prerequisites){
            in[i.first]++;
            out[i.second].push_back(i.first);
        }
        for(int i= 0; i < in.size(); i++)
            if(in[i] == 0){
                myque.push(i);
            }
        while(!myque.empty()){
            int front = myque.front();
            myque.pop();
            ret.push_back(front);
            for(auto i: out[front]){
                in[i]--;
                if(in[i] == 0){
                    myque.push(i);
                }
            }
        }
        if(ret.size() < numCourses) return {};
        return ret;
    }
private:
    queue<int> myque;
};