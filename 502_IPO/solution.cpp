struct Node
{
    int x,y;
    Node(int a, int b): x(a), y(b){}
};
bool operator >(Node a, Node b){
    if(a.x != b.x) return a.x > b.x;
        return a.y > b.y;
}
/*bool operator <(Node a, Node b){
    if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
}*/
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<Node, vector<Node>, greater<Node> > capital;
        priority_queue<int> profits;
        for(int i = 0; i < Capital.size(); i++){
            if(Capital[i] <= W)
                profits.push(Profits[i]);
            else
                capital.push(Node(Capital[i], Profits[i]));
        }
        while(k--){
            if(profits.empty() || profits.top() <= 0) break;
            W += profits.top();
            profits.pop();
            while(!capital.empty()){
                if(capital.top().x <= W){
                    profits.push(capital.top().y);
                    capital.pop();
                }else break;
            }
        }
        return W;
    }
};