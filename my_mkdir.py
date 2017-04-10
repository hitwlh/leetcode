# -*- encoding: utf-8 -*-
# python my_mkdir.py 16. 3Sum Closest
# 创建题号文件夹，创建readme.txt并输入一些固定信息，创建solution.cpp
# 第二行是执行样例
import sys 
import os

def f(str):
    return str.isdigit or str.isalpha

print "hello"
if len(sys.argv) < 3:
    sys.exit(-1)
print "脚本名：", sys.argv[0]
nPos = sys.argv[1].index('.') 
s = sys.argv[1][0:nPos]
for i in range(2, len(sys.argv)): 
    s += "_" + sys.argv[i]
print s
s = filter(f, s)
print s
MKDIR = "mkdir " + s
TOUCH = "touch " + "./" + s +"/readme.txt"
os.system(MKDIR)
os.system(TOUCH)
TOUCH = "touch " + "./" + s + "/solution.cpp"
os.system(TOUCH)
#OPEN = "open ./" + s
#os.system(OPEN)



README = "echo \"" + s +"\"" + " >> " + "./" + s +"/readme.txt"
os.system(README)

README = "echo \"\n\" >> " + "./" + s +"/readme.txt"
os.system(README)

README = "echo \"题目大意\" >> " + "./" + s +"/readme.txt"
os.system(README)

README = "echo \"\n\" >> " + "./" + s +"/readme.txt"
os.system(README)
README = "echo \"解决方案\" >> " + "./" + s +"/readme.txt"
os.system(README)

README = "echo \"\n\" >> " + "./" + s +"/readme.txt"
os.system(README)


README = "echo \"样例\" >> " + "./" + s +"/readme.txt"
os.system(README)

README = "echo \"\n\" >> " + "./" + s +"/readme.txt"
os.system(README)

SUBLIME = "subl " + "./" + s +"/solution.cpp"
os.system(SUBLIME)
SUBLIME = "subl " + "./" + s +"/readme.txt"
os.system(SUBLIME)
