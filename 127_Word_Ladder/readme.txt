127_Word_Ladder


题目大意
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.


解决方案
题目翻译，就是给初始串beginWord和目标串endWord，然后给一系列中间串。要通过中间串将beginWord转化成endWord，并且要使用最少的步数。
其实挺容易的，就是广搜一下。有几个注意点：
1. 由于需要返回做了几次转换，因此我用了两个队列，每次一个队列有内容时，就把下一层push到另一个队列，如果队列空了，就说明某层遍历玩了，ret+1，然后把下一个队列拿来处理。
2. 在找s的邻接串的时候。可以遍历wordList一次，找差一个字符的串。假设串长是k，这个的时间开销是wordList.size() * k
另一种算法是对wordList建立一个map，然后对s的每个位置的字符修改成a到z，去看map里有没有，如果有，就找到了。这个的时间开销是26 * k
solution.cpp里的是map的做法，原先的做法是代码里被注释的部分。时间对比大概5倍。从前10%多到前70%多

样例

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

