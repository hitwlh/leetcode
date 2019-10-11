class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> out(numCourses, vector<int>());
        for(auto i: prerequisites){
            in[i.first]++;//需要先上i.second, 再上i.first
            out[i.second].push_back(i.first);
        }
        for(int i= 0; i < in.size(); i++)
            if(in[i] == 0){
                myque.push(i);
                course++;
            }
        while(!myque.empty()){
            int front = myque.front();
            myque.pop();
            for(auto i: out[front]){
                in[i]--;
                if(in[i] == 0){
                    myque.push(i);
                    course++;
                }
            }
        }
        return course == numCourses;
    }
private:
    queue<int> myque;
    int course = 0;
};