/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        return (begins.top()++)->getInteger();
    }

    bool hasNext(){
        while(!begins.empty()){
            if(begins.top() == ends.top()){
                begins.pop();
                ends.pop();
            }else{
                if(begins.top()->isInteger()) return true;
                vector<NestedInteger>::iterator b, e;
                b = begins.top()->getList().begin();
                e = begins.top()->getList().end();
                begins.top()++;
                begins.push(b);
                ends.push(e);
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */