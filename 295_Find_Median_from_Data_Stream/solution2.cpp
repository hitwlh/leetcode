class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        ;
    }
    
    void addNum(int num) {
        lq.push(num);
        if(lq.size() > rq.size()+1){
            rq.push(lq.top());
            lq.pop();
        }
        if(rq.size() > 0 && lq.top() > rq.top()){
            int tmp1 = lq.top(), tmp2 = rq.top();
            lq.pop(), lq.push(tmp2);
            rq.pop(), rq.push(tmp1);
        }
    }
    double findMedian() {
        if(lq.size() > rq.size()) return lq.top();
        return ((double) lq.top() + rq.top()) / 2;
    }
private:
    priority_queue<int> lq;
    priority_queue<int, vector<int>, greater<int>> rq;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */