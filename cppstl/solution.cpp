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
char c;
string str;
stringstream stream;
stream << c;
str = stream.str();

//优先队列
priority_queue<pair<int, int>> mypq;
mypq.push( make_pair(x.second, x.first));

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