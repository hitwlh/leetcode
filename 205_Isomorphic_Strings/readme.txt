205_Isomorphic_Strings


题目大意
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Note:
You may assume both s and t have the same length.



解决方案
用一个大小为128的数组，来建立从a到b的映射。但是需要注意的是，这个映射可能是多对一
要保证是一一映射才行，所以应该反过来再做一遍。





样例
ab
aa
false

ab
ab
true

