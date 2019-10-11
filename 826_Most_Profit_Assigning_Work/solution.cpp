struct node{
    int difficulty, profit;
    node(int a, int b): difficulty(a), profit(b){}
};
bool compare(node a, node b){
    return a.difficulty < b.difficulty;
}
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<node> jobs;
        for(int i = 0; i < difficulty.size(); i++)
            jobs.push_back(node(difficulty[i], profit[i]));
        sort(jobs.begin(), jobs.end(), compare);
        sort(worker.begin(), worker.end());
        int i = 0, most_profit = 0, j = 0, ret = 0;
        while(i < jobs.size() and j < worker.size()){
            while(i < jobs.size() and jobs[i].difficulty <= worker[j]){
                most_profit = max(most_profit, jobs[i].profit);
                i++;
            }
            ret += most_profit;
            j++;
        }
        ret += (worker.size() - j) * most_profit;
        return ret;
    }
};