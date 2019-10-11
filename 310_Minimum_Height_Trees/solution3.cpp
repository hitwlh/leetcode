class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        int startindex, endindex, node = 0;
        vertex.assign(n, {}), visit.assign(n, false);
        for(auto i: edges){
            vertex[i.first].push_back(i.second);
            vertex[i.second].push_back(i.first);
        }
        myque.push(node);
        visit[node] = true;
        while(!myque.empty()){
            startindex = myque.front();
            myque.pop();
            for(auto target: vertex[startindex]){
                if(!visit[target]){
                    visit[target] = true;
                    myque.push(target);
                }
            }
        }
        visit.assign(n, false);
        myque.push(startindex);
        myque.push(-1);
        visit[startindex] = true;
        int length = 0;
        while(!myque.empty()){
            if(myque.front() == -1){
                myque.pop();
                if(myque.empty()) break;
                length++;
                myque.push(-1);
            }
            endindex = myque.front();
            myque.pop();
            for(auto target: vertex[endindex]){
                if(!visit[target]){
                    visit[target] = true;
                    myque.push(target);
                }
            }
        }
        unordered_map<int, bool> s1, s2;
        visit.assign(n, false);
        myque.push(startindex);
        myque.push(-1);
        visit[startindex] = true;
        int el = (length+1) / 2, el2 = (length+1)/2;
        while(el >= 0){
            if(myque.front() == -1){
                myque.pop();
                if(myque.empty()) break;
                el--;
                myque.push(-1);
            }
            node = myque.front();
            myque.pop();
            if(el == 0 || (el == 1 and length%2==1))
                s1[node] = true;
            for(auto target: vertex[node]){
                if(!visit[target]){
                    visit[target] = true;
                    myque.push(target);
                }
            }
        }
        while(!myque.empty()) cout << myque.front()<< " ", myque.pop();
        visit.assign(n, false);
        myque.push(endindex);
        myque.push(-1);
        visit[endindex] = true;
        while(el2 >= 0){
            if(myque.front() == -1){
                myque.pop();
                if(myque.empty()) break;
                el2--;
                myque.push(-1);
            }
            node = myque.front();
            myque.pop();
            if(el2 == 0 || (el2 == 1 and length%2 == 1))
                s2[node] = true;
            for(auto target: vertex[node]){
                if(!visit[target]){
                    visit[target] = true;
                    myque.push(target);
                }
            }
        }
        vector<int> ret;
        for(auto i: s1)
            if(s2.find(i.first) != s2.end())
                ret.push_back(i.first);
        return ret;
    }
private:
    queue<int> myque;
    vector<bool> visit;
    vector<vector<int>> vertex;
};