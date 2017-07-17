49_Group_Anagrams


题目大意
Given an array of strings, group anagrams together.


解决方案
这题比较简单，整体就是把每个string映射到它属于的组里去。
第一种映射方法是对每个单词sort，这样属于一类的sort完后就是相等的了
第二种映射方法是用int[26]的数组记录每个字母出现的次数，然后把这个数组转化成string(注意要添加分隔符，否则可能错位12/3 vs 1/23)

这题的写法运用到的stl内容值得参考




样例
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

