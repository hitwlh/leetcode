290_Word_Pattern


题目大意
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.



解决方案
先把那些单词放到一个vector里头，然后建立一一映射就是了。注意不能是验证了是单射就返回true
one-time-attention
处理str的时候，每次都是按照" "去做查找和erase，因此查到最后一个单词的时候，会发现最后什么都没有，这就大错特错了，直接导致死循环，因为最后一个单词后面没有空格。因此一开始在str最后添加一个空格。

样例
Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

