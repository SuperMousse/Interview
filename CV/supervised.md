1. k nearest neighbours

2. principal component analysis 
![](http://latex.codecogs.com/gif.latex?\\X={x_1, x_2, ..., x_n})
输入：n维样本集$X={x_1, x_2, ..., x_n}$，要降维到的维数$n_{'}$.
输出：降维后的样本集Y

a.对所有的样本进行中心化
b.计算样本的协方差矩阵C = 1 / n XX^{\top}
c.求出协方差矩阵的特征值及对应的特征向量
d.将特征向量按对应特征值大小从上到下按行排列成矩阵，取前k行组成矩阵P
e.Y=PX即为降维到k维后的数据
