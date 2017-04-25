class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg;
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
            que.pop();
            for(int i = 0; i < outdeg[top].size(); i++){
                if(!(--indeg[outdeg[top][i]]))
                    que.push(outdeg[top][i]);
            }
        }
        for(int i = 0; i < indeg.size(); i++) if(indeg[i]) return false;
        return true;
    }
};