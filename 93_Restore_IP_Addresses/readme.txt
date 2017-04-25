93_Restore_IP_Addresses


题目大意
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

解决方案
简单地搜索就是了，先放置第一个点的位置，然后判断左侧是否合法，若合法，往下搜索第二个点的位置(深搜)，若不合法，直接break
需要注意的是合法判断，不仅仅是0~255就ok，还要有if(s.length()>1 && s[0] == '0') return false;就是说非0串不能用0开头

样例
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)