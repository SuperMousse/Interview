/*
***************************** 第一讲 01背包问题 ***************************************** 
*************************************************************************************** 
假设山洞里共有a,b,c,d ,e这5件宝物（不是5种宝物），它们的重量分别是2,2,6,5,4，
它们的价值分别是6,3,5,4,6，现在给你个承重为10的背包, 怎么装背包，可以才能带走最多的财富。

i  name weight value | j: 1   2   3   4   5   6   7   8   9   10
1   a     4     6    |    0   0   0   6   6   6   6   6   6   6
2   b     5     4    |    0   0   0   6   6   6   6   6   10  10
3   c     6     5    |    0   0   0   6   6   6   6   6   10  11
4   d     2     3    |    0   3 	3   6 	6   9 	9  	9 	10 	11
5   e     2     6    |    0   6 	6   9 	9   12  12 	15 	15 	15

// ************************ 二维动态规划 ************************
// f[i, j]表示到第i个宝物为止, 使用j大小的背包所获得的财富
for i in [1, 5]:
  for j in [W_i, 10]:
    // j in [1, 10] and j-W_i >= 0
    f[i, j] = max(f[i-1, j], f[i-1, j-W_i]+V_i)

f[1, 4]  = max(f[0, 4], f[0, 0]+V_1) = max(0, 0+6) = 6
f[1, 5]  = max(f[0, 5], f[0, 1]+V_1) = max(0, 0+6) = 6
f[1, 6]  = max(f[0, 6], f[0, 2]+V_1) = max(0, 0+6) = 6
f[1, 7]  = max(f[0, 7], f[0, 3]+V_1) = max(0, 0+6) = 6
f[1, 8]  = max(f[0, 8], f[0, 4]+V_1) = max(0, 0+6) = 6
f[1, 9]  = max(f[0, 9], f[0, 5]+V_1) = max(0, 0+6) = 6
f[1, 10] = max(f[0, 10], f[0, 6]+V_1) = max(0, 0+6) = 6

f[2, 5]  = max(f[1, 5], f[1, 0]+V_2) = max(6, 0+4) = 6
f[2, 6]  = max(f[1, 6], f[1, 1]+V_2) = max(6, 0+4) = 6
f[2, 7]  = max(f[1, 7], f[1, 2]+V_2) = max(6, 0+4) = 6
f[2, 8]  = max(f[1, 8], f[1, 3]+V_2) = max(6, 0+4) = 6
f[2, 9]  = max(f[1, 9], f[1, 4]+V_2) = max(6, 6+4) = 10
f[2, 10] = max(f[1, 10], f[1, 5]+V_2) = max(6, 6+4) = 10


f[3, 6]  = max(f[2, 6], f[2, 0]+V_3) = max(6, 0+5) = 6
f[3, 7]  = max(f[2, 7], f[2, 1]+V_3) = max(6, 0+5) = 6
f[3, 8]  = max(f[2, 8], f[2, 2]+V_3) = max(6, 0+5) = 6
f[3, 9]  = max(f[2, 9], f[2, 3]+V_3) = max(10, 0+5) = 6
f[3, 10] = max(f[2, 10], f[2, 4]+V_3) = max(10, 0+5) = 6 // 此时发现f[2, 4]并未进行计算,因此需要把f[2, 4]从f[1, 4]继承下来

伪代码修正如下:
for i in [1, 5]:
  for j in [1, 10]:
    if j-W_i >= 0:
      f[i, j] = max(f[i-1, j], f[i-1, j-W_i]+V_i)
    else:
      f[i, j] = f[i-1, j]
      
// ************************ 一维动态规划 ************************
   f[i, j] = max(f[i-1, j], f[i-1, j-W_i]+V_i) 
=> f[j] = max(f[j], f[j-W_i]+V_i)

若不对j的循环顺序进行更改:
for i in [1, 5]:
  for j in [1, 10]:
    f[j] = max(f[j], f[j-W_i]+V_i)
    
f[1, 4]  = max(f[0, 4], f[0, 0]+V_1) = max(0, 0+6) = 6
f[1, 5]  = max(f[0, 5], f[0, 1]+V_1) = max(0, 0+6) = 6
f[1, 6]  = max(f[0, 6], f[0, 2]+V_1) = max(0, 0+6) = 6
f[1, 7]  = max(f[0, 7], f[0, 3]+V_1) = max(0, 0+6) = 6
f[1, 8]  = max(f[0, 8], f[0, 4]+V_1) = max(0, 0+6) = 6
f[1, 9]  = max(f[0, 9], f[0, 5]+V_1) = max(0, 0+6) = 6
f[1, 10] = max(f[0, 10], f[0, 6]+V_1) = max(0, 0+6) = 6

若正向更新, 会发现f[8]其实要使用f[0, 4]但是f[4]已经提前被更新成f[1, 4]了, 无法使用i-1的数据

所以将j进行逆序处理
for i in [1, 5]:
  for j in [10, 1]:
    f[j] = max(f[j], f[j-W_i]+V_i)
    
f[1, 10] = max(f[0, 10], f[0, 6]+V_1) = max(0, 0+6) = 6
f[1, 9]  = max(f[0, 9], f[0, 5]+V_1) = max(0, 0+6) = 6
f[1, 8]  = max(f[0, 8], f[0, 4]+V_1) = max(0, 0+6) = 6
f[1, 7]  = max(f[0, 7], f[0, 3]+V_1) = max(0, 0+6) = 6
f[1, 6]  = max(f[0, 6], f[0, 2]+V_1) = max(0, 0+6) = 6
f[1, 5]  = max(f[0, 5], f[0, 1]+V_1) = max(0, 0+6) = 6
f[1, 4]  = max(f[0, 4], f[0, 0]+V_1) = max(0, 0+6) = 6

此时发现, f[8]先使用了f[0, 4]然后f[1, 4]才进行更新

// 初始化细节
// 若恰好装满背包: 则f[0] = 0, f[1]...f[10]应该为-inf
// 若可以不装满背包: 则f[0]~f[10]均为0
// 因为初始化表示了没有任何物品放置时, 数组的合法状态
// 若必须装满背包, 则只有容量为0的背包的合理value为0, 其余状态没有合法解, 属于未定义
// 若不必装满背包, 则任何容量的背包都有合法解0, 因为可以不选取任何物品

// 常数优化
for i in [1, N]:
  for j in [V, W_i]:
    f[j] = max(f[j], f[j-W_i]+V_i)
中的j循环可以从 j \in [V, W_i] 优化为 j \in [V, max(W_i, V-\sum_{k=i}^{N}W_k)],
\sum_{k=i}^{N}W_k 表示i到N的所有物品重量

------------------------------------------------------>
       (V-\sum<=C_i)          C_i      (V-\sum>C_i)

若 \sum_{k=i}^{N}W_k <= W_i, 则max(W_i, V-\sum_{k=i}^{N}W_k)=W_i, 小于W_i由于背包容量不足不更新, 与未优化结果相同
若 V-\sum_{k=i}^{N}W_k > W_i, 则max结果为V-\sum_{k=i}^{N}W_k, 
                             a. 此时V-\sum_{k=i}^{N}W_k > W_i > 0, 表示背包总容量去除当前及后面的所有物品仍有剩余, 所以, 
                             背包的最大值一定可以达到, 即矩阵的右下角一定可达
                             b. 对于j >= V-\sum_{k=i}^{N}W_k, j-W_i >= V-\sum_{k=i+1}^{N}W_k
                             因此f[j] = max(f[j], f[j-W_i]+V_i)此时只计算了V-\sum_{k=i+1}^{N}W_k后面的元素
                              
i  name weight value | j: 1   2   3   4   5   6   7   
                          0   0   0   0   0   0   0  
1   a     1     6    |    *   *   6   6   6   6   6   
2   b     1     4    |    *   *   *   10  10  10  10   
3   c     1     5    |    *   *   *   *   15  15  15   
4   d     1     3    |    *   * 	*   * 	*   18 	18  	
5   e     1     6    |    *   * 	*   * 	*   *   12 	

for i in [1, N]:
  for j in [V, max(W_i, V-\sum_{k=i}^{N}W_k)]:
    f[j] = max(f[j], f[j-W_i]+V_i)

i = 1
max(W_i, V-\sum_{k=i}^{N}W_k)) = max(1, 7-4) = 3
f[7] = max(f[7], f[6]+V_1) = max(0, 0+6) = 6
f[6] = max(f[6], f[5]+V_1) = max(0, 0+6) = 6
f[5] = max(f[5], f[4]+V_1) = max(0, 0+6) = 6
f[4] = max(f[4], f[3]+V_1) = max(0, 0+6) = 6
f[3] = max(f[3], f[2]+V_1) = max(0, 0+6) = 6
f[1]在正常算法中应该更新, 此时省去

i = 2
max(W_i, V-\sum_{k=i}^{N}W_k)) = max(1, 7-3) = 4
f[7] = max(f[7], f[6]+V_2) = max(6, 6+4) = 10
f[6] = max(f[6], f[5]+V_2) = max(6, 6+4) = 10
f[5] = max(f[5], f[4]+V_2) = max(6, 6+4) = 10
f[4] = max(f[4], f[3]+V_2) = max(6, 6+4) = 10
f[3], f[2], f[1]在正常算法中应该更新, 此时省去

*/
