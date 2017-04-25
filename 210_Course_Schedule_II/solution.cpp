class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg, ret;
        indeg.assign(numCourses, 0);
        vector<vector<int>> outdeg;
        outdeg.assign(numCourses, {});
        for(int i = 0; i < prerequisites.size(); i++){
            indeg[prerequisites[i].first]++;
            outdeg[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        queue<int> que;
        for(int i = 0; i < numCourses; i++)
            if(!indeg[i])
                que.push(i);
        while(!que.empty()){
            int top = que.front();
            ret.push_back(top);
            que.pop();
            for(int i = 0; i < outdeg[top].size(); i++){
                if(!(--indeg[outdeg[top][i]]))
                    que.push(outdeg[top][i]);
            }
        }
        if(ret.size() < numCourses) return {};
        return ret;
    }
};