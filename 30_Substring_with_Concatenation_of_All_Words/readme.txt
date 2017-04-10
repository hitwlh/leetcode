30_Substring_with_Concatenation_of_All_Words


题目大意
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

解决方案
1.
我想到的暴力解法：首先对words里的单词建立哈希，然后对字符串s，以每个点为起点判断它们是否是words中的元素，如果是，记录下是哪个元素
然后从s的第0个元素开始往后遍历，words.size()那么多元素，判断这些元素是否构成words
容易错的点：

a.根据words建立了一个map<string, int> my_map，其中int就是my_map中元素的索引，但是第一个元素的索引是0，这里就错了，因为找不到的索引也是0，因此要改成从1开始，即：
my_map[words[i]] = i+1;
b.这种解法利用了一个性质：那就是s[i]为起点的串只能对应于words中一个确定的元素，（因为words的所有元素等长，所以不存在一个元素是另一个元素的前缀的情况），但是我忽略了一点：那就是words中可能有重复元素。如果有重复元素，那么一方面在建立索引的时候就要对重复元素做出考虑，另一方面在“从s的第0个元素开始往后遍历，words.size()那么多元素，判断这些元素是否构成words”这一步的时候也要做一个“允许元素重复的集合的相等判断”操作，这里我用的方法是优先队列。一开始没想到重复元素这个问题时我直接用sum来进行判断，会wa。
c.写equal的时候对有限队列用了[]，原来队列里是没有[]的。另外，尽管传的是&，但是在函数里把队列清空并不影响主函数，最后还是要在主函数里进行对队列进行清空才有效

这个解法保留在solution1.cpp里

2.
网上看到的，想法和解决方案1类似，但是写法不一样。
它的map保存的是string出现的次数而不是下标。这样后面的判断会变得非常简单。
这个思想值得借鉴，就是在判断“允许元素重复的集合的相等判断”时，可以统计每个字符的出现次数，当出现另一个元素数目相等集合时，如果那个集合里的元素不在第一个集合里，则不相等，如果那个集合里某个元素的出现次数大于第一个集合，也不相等，当判断完整个集合仍然没有不相等，就相等了。
效率比我的高了20%+
代码保存在solution2.cpp里

3.
第三种解法是双指针法，这个从2开始很容易想到，保留一个开头保留一个结尾，然后看开头和结尾中间的是否是就是words
有如下几种情况：
a.右指针距离左指针到了words的size()+1，就是了，把左指针放到res里，然后对左指针当前指向的字典元素+1，左指针往后挪一个
b.右指针指向的元素在剩下的字典里，对右指针当前指向的字典元素-1，右指针右移
c.右指针指向的元素不在剩下的字典里，如果左指针指向的元素在字典里，对左指针当前指向的字典元素+1，左指针往后挪一个
d.左指针在右指针右边，将左指针的值赋给右指针

上面这个逻辑非常重要！！！推敲了好几遍

注意有几个地方容易错
a.如果最后匹配成功，也就是string里最末尾的words[0].size()个元素完成最后的匹配，那光是用while循环就会把这个解漏掉，需要在while外面再加一个判断if( (right_index - left_index) / m == n)
b.在上面的b里，需要判断“右指针指向的元素在剩下的字典里”，这里有两层意思，第一次是右指针指向的元素在字典里，第二层是在剩下的字典里。
一个元素是否在字典中应该用 m1.count(s.substr(right_index, m)) > 0 
是否在剩下的字典里应该用m1[s.substr(right_index, m)] > 0
合起来应该写作if(m1.count(s.substr(right_index, m)) > 0 && m1[s.substr(right_index, m)] > 0)，不能直接用m1[s.substr(right_index, m)] > 0来代替，
原因：
对于unordered_map<string, int> m1;
如果"dd"不在m1中也就是m1.count("dd") < 0，用了if(m1["dd"] > 0)会导致m1.count("dd") > 0

c.在for循环判断中如果用了s.length()-1，那就要当心了！
s.length()是unsigned类型，所以它-1不会是负数，而会变成INT_MAX
really important!!!



样例
s: "barfoothefoobarman"
words: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

