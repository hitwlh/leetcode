300_Longest_Increasing_Subsequence


题目大意
Given an unsorted array of integers, find the length of longest increasing subsequence.
For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?





解决方案
有O(n^2)和O(nlogn)两种解法。

solution1
直接用动规。从前往后或从后往前都可以。
soluiton1.cpp里的是从后往前的：以最后一个元素为起点形成的最大不递减子串明显是它自己。以a[i]为起点形成的最大不递减子串是从a[i]往右遍历，，找到所有<=a[i]的元素的不递减子串的最大长度，再+1作为a[i]的不递减子串长度
O(n^2)时间复杂度



solution2
参考http://lib.csdn.net/article/datastructure/18433

从左往右遍历，gr[i]表示(长度为i+1的)最大不递减子串右侧元素最小是d[i]
对nums从左到右遍历
初始：len = 0, gr[len++] = nums[0];
往右遍历nums  for(int i = 1; i < nums.size(); i++)
if(nums[i] < gr[0]) gr[0] = nums[i];
else if(nums[i] > gr[len-1]) gr[len++] = nums[i];
else{
    int it = find(gr, len, nums[i]);
    gr[it] = nums[i];
}
gr的更新规则如上。
1. 如果nums[i] < gr[0]  gr[0] = nums[i];
2. 如果nums[i] > gr[len-1] gr[len++] = nums[i];
3. 找到j, 满足gr[j] < nums[i] && gr[j+1] >= nums[i]， 更新gr， gr[j+1] = nums[i]


这里有2点要搞清楚：
1. gr[j+1] 表示的是长度为j+2的不递减子串右边最小可以是gr[j+1]，但是长度为j+2的串的倒数第二个数字怎么办呢？怎么保证更新最后的数字的时候倒数第二个数字比最后的数字小(或等于)。
以1, 2, 10, 20, 8, 9为例
前4步得到：
1
1, 2
1, 2, 10
1, 2, 10, 20
即dp[0] = 1 dp[1] = 2 dp[2] = 10 dp[3] = 20

执行完第5步：
1
1, 2
1, 2, 8
1, 2, 10, 20
即dp[0] = 1 dp[1] = 2 dp[2] = 8 dp[3] = 20


执行第6步是这样吗？：
1
1, 2
1, 2, 8
1, 2, 10, 9
比较9得到9>8 9<20，所以直接更新20？
不对，由于8更新了10，将10改成了8, 因此应该是这样：
1
1, 2
1, 2, 8
1, 2, 8, 9
说明直接将10改成9是对的，不会出现改完后9前面的数字比9大的情况。

而如果是：1, 2, 10, 20, 19
1
1, 2
1, 2, 10
1, 2, 10, 20
那最后直接变成
1
1, 2
1, 2, 10
1, 2, 10, 19
就好了，因为dp[2]=10没有变过，21前面的是10，而找位置的时候确保了19 > 10，所以直接将20修改成19就行了。




2. 在更新规则的第3条，要在有序的数组里找第一个>=target的元素的下标，可以调用lower_bound
在代码里自己写的find。
注意一定要这样更新：
if(gr[mid] < target) left = mid + 1;
else right = mid;
如果写成
if(gr[mid] > target) right = mid - 1;
else left = mid;
那就大错特错了！！！想想(假设需要找E)
ABCDEEEEEFF需要返回的是第一个E的位置，也就是4。
如果是第二种写法，那就是left从4一直往8靠过去，大错特错！！！
而第一种写法是right从8往4靠！！！非常有意思

样例


