#### 京东一面面经:  
##### 1. 疯狂问简历, 简历里面每个项目都讲讲干嘛的, 计时30分钟  
##### 2. 基础知识  
a. 如何训练一个模型, loss不下降该怎么办  
b. loss出现nan该怎么办  
c. 损失函数有哪些? cross entropy, l1, l2, 比较一下  
d. 讲一下k-means, EM算法, 他们之间有什么关系  
e. 讲一下Transformer, self-attention, scale因子作用? 用了什么norm, layernorm的公式是什么, 作用? 多头有什么用?     
f. 讲一下拉普拉斯矩阵, 谱域图卷积怎么做? 空域图卷积怎么做? 空域图卷积一般框架是什么(read-out?)? 空域图卷积常见的有哪些? GraphSAGE, GIN, 结构?  
g. 还有哪些Graph Embedding的算法 DeepWalk, LINe, Node2vec,   
h. 讲一下机器学习的偏差和方差, bagging和boosting都是什么?  
i. 讲一下随机森林和GBDT?  
j, 讲一下LSTM, LSTM有几个门, 为什么可以解决梯度消失?    
k. 讲一下word2vec, CBOW, skip-gram都是什么, 负采样技术?    

##### 3. 两道算法题, 用时20分钟  
a. pow(x, n)快速幂  
b. isBalanceTree(TreeNode* root), 判断输入的树是否是平衡二叉树  


##### 4. 总结: 
a. GBDT讲的不太好, 注意改进;  
b. EM算法没回答上来；  
k-means是EM算法的特例, EM算法中考虑了隐变量z, 数据x, 标签y以及参数theta, 其中E步骤实际上是在求P[z|x]的条件概率分布，然后根据条件概率得到对数条件期望, 然后M步骤根据隐变量的对数条件期望代入极大似然估计中对于参数theta进行估计;   
k-means中每个样本所属的类就可以看成是一个隐变量，在E步中，我们固定每个类的中心，通过对每一个样本选择最近的类优化目标函数, 就得到了对于隐变量的条件概率分布估计，在M步，重新更新每个类的中心点为均值, 实际上是根据极大似然估计推导出来的;    
c. 空域图卷积的一般结构?   消息传递网络： 消息传递=>状态更新=>图读出(read-out, graph pooling)   
GraphSAGE的框架实际上就是消息传递和状态更新这一步骤  
