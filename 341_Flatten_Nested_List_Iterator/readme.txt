341_Flatten_Nested_List_Iterator


题目大意
Given a nested list of integers, implement an iterator to flatten it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
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


解决方案
翻译：看example就能理解题意了。

一开始没搞清楚NestedInteger的接口怎么用。
如果NestedInteger里只有一个整数，isInteger返回true，getInteger得到这个整数。否则getList将NestedInteger中的每个元素放到一个vector里，然后返回这个vector。

这题解法有好几种。
solution里的是begins栈保存一个vector的迭代器，ends栈保存同一个vector的尾。因此处理的时候，如果begins栈顶当前指向的元素是int，那直接返回就ok，否则就对这个元素调用getList，然后把begins栈顶往前移动一下，再将得到的vector压入begins ends
solution.cpp



这种解法比较节省空间。
还有一种做法是直接将整个NestedInteger压入栈中。然后反复处理栈顶。solution2.cpp


样例
Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
