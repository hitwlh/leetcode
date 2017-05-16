struct Node {
    int val, i, j;
    Node(int i, int j, int val) :i(i), j(j), val(val) {}
    Node() {}
    bool operator < (const Node & x)const {
        return val > x.val;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Node> mypq;
        mypq.push(Node(0, 0, matrix[0][0]));
        Node front;
        while(k--){
            front = mypq.top();
            mypq.pop();
            if(front.i == 0 && front.j + 1 < matrix.size())
                mypq.push(Node(front.i, front.j+1, matrix[front.i][front.j+1]));
            if(front.i + 1 < matrix.size())
                mypq.push(Node(front.i+1, front.j, matrix[front.i+1][front.j]));
        }
        return front.val;
    }
};