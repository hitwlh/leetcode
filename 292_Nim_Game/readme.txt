292_Nim_Game


题目大意

You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.


解决方案
递推地看待：
A.剩下1/2/3块，谁先选谁赢(谁进入A即可赢)
B.剩下4块，我选1/2/3块，都会变成对方先选的A，则我输(谁进入B即输)
C.剩下5块，我选1块，对方进入B，(谁进入C即赢)
D.剩下6块，我选2块，对方进入B，（谁进入D即赢）
E.剩下7块，我选3块，对方进入B，（谁进入E即赢）
F.剩下8块，我选1/2/3，会变成对方进入E/D/C，（谁进入F即输）
剩下9块，我赢
剩下10块，我赢
剩下11块，我赢
剩下12块，我输
...

样例

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

