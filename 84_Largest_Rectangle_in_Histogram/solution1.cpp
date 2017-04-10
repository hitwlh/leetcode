struct MySegmentTreeNode
{
    int start, end;
    int cnt;
}tree[3*1000000 + 5];
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
            return 0;
        build(heights, 1, 0, heights.size()-1);
        return ret(heights, 0,heights.size()-1);
    }
private:
    void build(vector<int>& heights, int root, int start, int end)
    {
        tree[root].start = start;
        tree[root].end = end;
        if(start == end){
            tree[root].cnt = start;
            return;
        }
        int mid = (start+end)/2;
        build(heights, root*2, start, mid);
        build(heights, root*2+1, mid+1, end);
        tree[root].cnt = heights[tree[root<<1].cnt] < heights[tree[root<<1|1].cnt] ? tree[root<<1].cnt : tree[root<<1|1].cnt;
    }
    int search(vector<int>& heights, int root, int start, int end)
    {
        if(tree[root].start == start && tree[root].end == end)
            return tree[root].cnt;
        int mid = (tree[root].start+tree[root].end)/2;
        if(mid>=end)    
            return search(heights, root*2, start, end);
    else if(mid<start)
            return search(heights, root*2+1,start, end);
        else{
            int s1 = search(heights, root*2, start, mid);
            int s2 = search(heights, root*2+1, mid+1, end);
            return heights[s1]  < heights[s2]?s1:s2;
        }
    }
    int ret(vector<int>& heights, int start, int end)
    {
        if(end<start)
            return 0;
        int mid = search(heights, 1, start, end);
        int s1 = (end-start+1)*heights[mid];
        int s2 = ret(heights, start, mid-1);
        int s3 = ret(heights, mid+1, end);
        return max(s1, max(s2, s3));
    }
};