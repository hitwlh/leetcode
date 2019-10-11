402_Remove_K_Digits


题目大意
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.


将给定的数字去掉k位，要使得留下来的数字最小

解决方案
显然如果能把全部remove掉那就返回0就是了
如果不能，返回的数字的位数是确定的，那么应该优先让最高位最小，然后让次高位最小...
也就是说应该从左往右看k+1位，找到最小值，然后切掉最小值左侧的，让z最小值变成答案的最高位(如果本来就是最高位就不用切了)，然后递归调用右侧进行执行
one-time-attention
1. 既然是递归调用，如果最高位是0，就应该返回0，而不是删掉最高位的0， 因为调用的时候并不知道左侧是否还有数字，如果左侧有，就不能删除了。因此应该最终在main函数里去删除左侧连续的0
2. 切除k位可以从左向右看k+1个数，因为连着切最左k个的话拿就留下第k+1作为最高位了
solution1.cpp



但是这样实现的话复杂度不是O(N)的，因为找到min意味着它右侧被找过一遍，下次调用的时候为了找min老min右侧被遍历过的那段又会遍历一遍。这是重复计算。一开始想的是记录下本次min的右侧的min，这样下次就能直接跳到那个min那里，但是这里又产生问题了，那就是跳到右侧的第二个min之后，又需要它右侧的min，这时只能重新从第二个min右侧再遍历，因此并没什么用。比如45678这个串。找到4和5之后，下次问题变成5和？，想解答？是多少就需要从5往右继续遍历

我认为有两种思路能优化这种反复查询的情况
一个是建立线段树，然后反复查找[0, k+1]区间最小值，然后对右侧递归处理
线段树开销是O(NlogN),需要查找至多(N-k)次，总查找开销至多为O(NlogN)，因此总开销是O(NlogN)
一个是从左到右一段一段地处理，每段处理k+1个
处理一段的时候，新建一个string，拷贝这一段，然后sort这个string，就一次知道了最小、次小...是多少
然后处理这个段的时候，从左到右，如果是最小，切掉其左侧，往右侧处理找次小...
这样的开销就是O(KlogK)，总开销是O((N/K)logK)



看了下网上的解法，只需要维持一个单调不递减的栈就行了
如果不能切除，返回。
否则
如果栈顶比当前的大，那就切掉栈顶，重复判断
如果栈顶不比当前的大，当前的入栈
solution2.cpp
one-time-attention
如果k不小于0，也就是说还需要切
1. 如果移除结果左侧的0后length<k，返回"0"（也就是说把剩余的全部切掉）
2. 要把右侧的k个数字切掉然后返回ret

solution3.cpp
最容易理解，应该维持一个从左到右递增的序列，如果有更小的数字，就把它左边比它大的给删掉。



样例

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
