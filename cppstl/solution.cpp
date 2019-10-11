//sum
accumulate(nums.begin(), nums.end(), 0);

queue<pair<TreeNode*, TreeNode*>> myq;
myq.push(make_pair(left->left, right->right));
TreeNode* left = get<0>(myq.front());

vector<int> in;
auto it = in.begin();
it = in.insert(it, p->val);


queue<pair<TreeNode*, int>> tree;
tree.push(make_pair(root, level));
top = tree.front().first;
level = tree.front().second;

//int to string
stringstream ss;
ss << root->val;
string str = ss.str();


std::string pi = "pi is " + std::to_string(3.1415926);
std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";

//string to int
string str = "123";
int n = atoi(str.c_str());

//char to string
1.
""+c

2.
string s(1, c)

3.
char c;
string str;
stringstream stream;
stream << c;
str = stream.str();

//优先队列
priority_queue<pair<int, int>> mypq;
std::priority_queue<int, vector<int>, greater<int>> mypq;
mypq.push( make_pair(x.second, x.first));


struct Node
{
    int x,y;
    Node(int a, int b): x(a), y(b){}
};
bool operator >(Node a, Node b){
    if(a.x != b.x) return a.x > b.x;
        return a.y > b.y;
}
priority_queue<Node, vector<Node>, greater<Node> > capital;

struct ListNodeComp {
    bool operator () (const ListNode *n1, const ListNode *n2) const {
        return n1->val > n2->val;
    }
};
priority_queue<ListNode*, vector<ListNode*>, ListNodeComp> my_pq;

自定义结构1
struct Node {
    int val, i, j;
    Node(int i, int j, int val) :i(i), j(j), val(val) {}
    Node() {}
    bool operator < (const Node & x)const {
        return val > x.val;
    }
};
自定义结构2(第23题，需要在节点外自己定义比较函数)
bool operator () (const ListNode *n1, const ListNode *n2) const {
    return n1->val > n2->val;
}

//排序、去重
sort(nums1.begin(), nums1.end());
auto it = unique(nums1.begin(), nums1.end());
nums1.resize(distance(nums1.begin(),it));

//erase
ret.push_back(nums1[j]);
auto it = nums1.begin()+j;
nums1.erase(it);


//找minmum
*min_element(minPath.begin(), minPath.end());

//遍历map
for(auto it:mymap) it.second
这种方式不是引用，修改不了mymap
for(auto it = mymap.begin(); it != mymap.end(); it++)
it->second可以修改mymap


map::lower_bound(key):返回map中第一个大于或等于key的迭代器指针
map::upper_bound(key):返回map中第一个大于key的迭代器指针


//lower_bound  upper_bound
ForwardIter lower_bound(ForwardIter first, ForwardIter last, const _Tp& val)算法返回一个非递减序列[first, last)
中的第一个大于等于值val的位置。
ForwardIter upper_bound(ForwardIter first, ForwardIter last, const _Tp& val)算法返回一个非递减序列[first, last)
中第一个大于val的位置。


//获取中位数
nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
auto mid = *(nums.begin() + nums.size()/2);


//堆
struct Node {
    int val, i, j;
    Node(int i, int j, int val) :i(i), j(j), val(val) {}
    Node() {}
    bool operator < (const Node & x)const {
        return val > x.val;
    }
};
priority_queue<Node> mypq;
mypq.push(Node(0, 0, matrix[0][0]));

//获取

/*{
  'articles': [
    [
      {
        'text': 'This is a short article.',
        'width': 15,
      },
      {
        'text': 'Now for a longer article. This one has a lot of text.',
        'width': 16,
      },
    ],
    [
      {
        'text': 'Another article with medium length.',
        'width': 32,
      },
    ],
  ],
  'width': 32,
}

+--------------------------------+
|This is a short|Now for a longer|
|article.       |article. This   |
|               |one has a lot of|
|               |text.           |
+--------------------------------+
|Another article with medium     |
|length.                         |
+--------------------------------+
*/