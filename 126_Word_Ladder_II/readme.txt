126_Word_Ladder_II


题目大意
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.





解决方案
这题是127题的进阶版本，127只需要返回需要的步数，这题需要返回所有路径

首先要注意，这里需要“一层一层”地处理，某一层没处理完时，不能修改下一层的串为已访问过，因为这一层后面未处理的串可能有不同路径可以到下一层同样的串。但是处理一层之前要先把这一层所有的串都标记为已处理过，如果在处理到某个串之前才进行标记，可能某一层第一个结点广搜到下一层的串，就是这一层后面的串



其实这题比较简单，网上把这题“复杂化”了，噱头一大堆，ac率最低...
说到底还是bfs，但是问题是bfs保存的“树”，一开始的做法也超时了，因为我在每个节点上都保存了从树根到节点的路径。
这样做当然不错，但是这题的数据貌似比较tight，所以不能在节点保存整个路径。
改为遍历到一个结点时，存储它的"父亲"列表。
数据结构是unordered_map<string, vector<string>>mymap2; 最后遍历到了endWord时，就可以退出。这时所有路径上的所有结点的所有父亲信息都有了，直接用dfs从后到前反推建立原始的串就ok
有一个one-time-attention
以输入
"red"
"tax"
["ted","tex","red","tax","tad","den","rex","pee"]
为例，解是[["red","ted","tad","tax"],["red","ted","tex","tax"],["red","rex","tex","tax"]]
由于tex有两个不同的父亲，因此tad和rex都可以让tex入队列，而如果tex入两次队列，就会导致tax找到“两个”一样的father“tex”，事实上tax的“tex”father只有一个，是以tex为father的路径有两条，因为tex有两个father。如果tax有两个father，后面的dfs就不对了。所以入队的时候要确保队列中无重复元素。所以队列是用unordered_set<string> que[2];表示的。其实这里的队列也不是严格的广搜的队列了，因为某一层内部谁先谁后没有关系。







样例
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

