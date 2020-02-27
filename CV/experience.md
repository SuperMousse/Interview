#### 1. https://zhuanlan.zhihu.com/p/75007429  
##### (1). BN的基本原理，其中的两个参数的作用?  
a. BN使得网络中每层输入数据的分布相对稳定，加速模型学习速度。使得模型对网络的参数不那么敏感，使学习更加稳定。可以缓解梯度消失的问题.  
b. BN的两个参数为经过不断学习学习出来的还原特征的平移和缩放的因子，用于对特征的分布的还原，这些操作均在BN层中完成。  

##### (2). 过拟合的解决办法?    
   a. Early stopping  
   b. 数据集扩增（增强等）  
   c. 正则化方法   
   d. Dropout  
##### (3). 梯度爆炸的原因和解决方案？ 
原因: a. 选择了不恰当的损失函数   
     b. 学习率过高   
     c. 模型问题（网络模型过深）  
     
解决方法：a.控制反向传播的范围，梯度Clip   
        b.使用batchnorm、预训练加微调（模型从0训练比较困难）   
        c.调小学习率   
        d.添加权重W正则化项对loss做约束，梯度过大的时候进行惩罚。   
        e.残差结构   
##### (4) 梯度消失的原因和解决方案？ 
原因: a.选择了不恰当的损失函数   
     b.选择了不恰当的激活函数，如sigmoid   
     c.网络的层数过深  
     
解决方法： 
      a.使用batchnorm、预训练加微调（模型从0训练比较困难） 
      b.选择relu、leaky relu等激活函数  
      c.残差结构
      
##### (5) 激活函数如果不是以0为中心的影响:  降低模型收敛速度  https://liam.page/2018/04/17/zero-centered-active-function/
以sigmoid为例, 其输出值恒为正数
f(z) = \sum{w_i * x_i + b} 
=> 对w_i偏导: x_i * (Loss对f偏导) * (f对z偏导)
因此当前层的不同w_i, 其梯度由前一层的输出值影响, 若前一层为sigmoid，则不同x_i均为正值, 则当前层的参数更新只能全正/全负, 如果有的参数需要正
向更新, 有的参数需要负向更新, 那么就需要z字型绕很久, 才能收敛到最优解 

##### (6) 其他:  
优点：勤奋努力（高考）、适应环境快（研究方向多元）、待人比较温和（容易交朋友）、抗压能力强（身兼多职）
缺点：不太清楚如何拒绝别人（因此耽误了自己项目进度）、过于追求明白原理（有时项目进度会慢）



#### 2. 目标检测相关  
##### (1) R-CNN  
a. 利用selective search对图像生成1K~2K的候选区域（region proposal)  
b. 将region proposal resize为统一大小，使用CNN对每个候region proposal提取特征  
c. 对区域进行分类：对从CNN output出来的特征向量送进每一类的SVM分类, 如果我有十个类别，那么每个region proposal要跑10个SVM，得到类别。这里为什么要用SVM而不是softmax，有一种说法是为了解决样本不均衡的问题，另外是早期神经网络还不如现在这样发达，当时SVM还是比较领先的分类器  
d. 修正：对CNN output的特征向量（这个特征向量和第4步中拿去喂给SVM的是一个向量）做回归（左上角右下角的四个坐标），修正region proposal的位置; proposal和ground truth的IOU>0.6时认为他们很接近, 这个时候proposal到ground truth的边界框变换可以认为是近似线性问题, 否则两个相距很远的边界框学习是一种非线性问题, Y=WX就是特征X的线性变换, Y为四维变量, 使用L1或者smooth L1进行训练

##### (2) Fast R-CNN：ROI pooling+FC取代SVM
a. selective search生成候选区域  
b. CNN抽特征(CNN全部3 * 3卷积还有padding, 卷积不会使得feature变小, 但是pooling的stride为2, 所以最后feature map会变成原来的1/16), 并使用候选区域进行ROI pooling; ROI pooling输入为proposal和feature map, 按照proposal取出feature map拼接起来(使用scale参数将原始的H、W映射为1/16H、1/16W), 然后2d pooling成相同channel, h, w 
c. 使用fc layer进行softmax分类(取代了SVM)以及边界框回归  

##### (3) Faster R-CNN: 使用RPN(Region Proposal Network)取代了Selective Search  
a. CNN抽特征, 3 * 3卷积feature map不变小, pooling stride为2, 最后feature map变为1/16  
b. RPN提出proposal, 双支路: positive/negative anchor支路, 边界框回归支路  
anchor分类支路: 输入featuremap (B, C, 1/16 H, 1/16 W), 做1 * 1卷积变为(B, 18, 1/16 H, 1/16 W), 18对应每个点上有9个anchor, resize到  (B * 1/16 H * 1/16 W, 2)判断positve/negative, positive的参与后续使用  
边界框回归支路: 输入featuremap (B, C, 1/16 H, 1/16 W), 做1 * 1卷积变为(B, 36, 1/16 H, 1/16 W), 36对应每个点上9个anchor的4的位置变换因子, 左右平移, 宽高缩放  
两支路融合每个点上9个anchor考虑是否positive和位置变换因子, 生成proposal
c. 利用RPN提出的proposal进行ROI pooling  
d. proposal feature map分类以及边界框回归, 分类将proposal和ground truth重叠大于0.7的认为是positive, 小于0.3的认为是negative, 这之间的不参与BP计算, 边界框回归使用smooth L1 loss
