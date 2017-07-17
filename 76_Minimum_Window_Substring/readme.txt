76_Minimum_Window_Substring


题目大意
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".




解决方案
从左到右保持一个滑动窗口，（移动右指针）记录窗口内出现过的字符，如果滑动到某个位置时窗口内包含了T：
把窗口左端多出的字符删掉(移动左指针)，直到找到第一个必要的左指针，然后把当前窗口内的字符串记下来就ok。
要点：要用两个map，一个表示t里的字符，一个表示窗口里的字符，然后用一个found变量指示当前已经找到多少个t中的字符

one-time-attention
1. 这里的代码用map出了问题：
关于map的operator[]，
If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value. Notice that this always increases the container size by one, even if no mapped value is assigned to the element (the element is constructed using its default constructor).
所以第九行不是
if(mymap1[s[right]] > 0){
而是
if(mymap1.find(s[right]) != mymap1.end() && mymap1[s[right]] > 0){


这里的map数据类型可以很容易改成vector，能更快。


样例
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

76_Minimum_Window_Substring


题目大意


解决方案


样例


