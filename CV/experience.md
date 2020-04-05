#### 1. https://zhuanlan.zhihu.com/p/75007429  
##### (1). BN的基本原理，其中的两个参数的作用?  
a. BN使得网络中每层输入数据的分布相对稳定，加速模型学习速度。使得模型对网络的参数不那么敏感，使学习更加稳定。可以缓解梯度消失的问题.  
b. BN的两个参数为为平移和缩放因子, 使得BN层后的输出能够还原变换前的输入特征分布, 从而保证模型的总体稳定性

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
c. 使用fc layer进行softmax分类(取代了SVM)以及边界框回归, fc层还用了svd减少参数量

##### (3) Faster R-CNN: 使用RPN(Region Proposal Network)取代了Selective Search  
a. CNN抽特征, 3 * 3卷积feature map不变小, pooling stride为2, 最后feature map变为1/16  
b. RPN提出proposal, 双支路: positive/negative anchor支路, 边界框回归支路  
anchor分类支路: 输入featuremap (B, C, 1/16 H, 1/16 W), 做1 * 1卷积变为(B, 18, 1/16 H, 1/16 W), 18对应每个点上有9个anchor, resize到  (B * 1/16 H * 1/16 W, 2)判断positve/negative, positive的参与后续使用  
边界框回归支路: 输入featuremap (B, C, 1/16 H, 1/16 W), 做1 * 1卷积变为(B, 36, 1/16 H, 1/16 W), 36对应每个点上9个anchor的4的位置变换因子, 左右平移, 宽高缩放  
两支路融合每个点上9个anchor考虑是否positive和位置变换因子, 生成proposal
c. 利用RPN提出的proposal进行ROI pooling  
d. proposal feature map分类以及边界框回归, 分类将proposal和ground truth重叠大于0.7的认为是positive, 小于0.3的认为是negative, 这之间的不参与BP计算, 边界框回归使用smooth L1 loss


#### 3. https://zhuanlan.zhihu.com/p/56813157
##### (1) 线性回归和逻辑回归的区别和联系？  
a. 线性回归用于回归问题，逻辑回归用于分类问题。    
b. 逻辑回归使用sigmoid激活函数。    
c. 线性回归可以使用最小二乘法(最小均方误差)作为损失，逻辑回归可以使用极大似然估计(交叉熵)    
d. 线性回归要去自变量和因变量之间存在线性关系；线性回归要求误差服从正态分布。   

e. 逻辑回归使用最大似然估计而不是最小二乘, 因为首先, 逻辑回归的最小二乘损失函数非凸, 容易陷入局部解, 最大似然是凸的; 其次, 因为导数的原因, 导致最小二乘在接近最优解的时候梯度几乎为0

##### (2) 训练过程中损失函数出现nan的原因？   
a. 可能存在脏数据，使得求log的时候，有0出现。    
b. 梯度爆炸：调小学习率；使用数据归一化方法（例如，减均值，除方差，或者加入normalizaiton例如BN，l2 normalizaiton）；更该参数初始化方法；减小batchsize；加入gradient_clipping；

##### (3) 为什么交叉熵可以作为损失函数？
我们希望模型学到的分布q和训练数据的分布p相同，即希望最小化KL散度KL(p,q)=\sum{p log(p/q)} = \sum{plogp - plogq} = -数据分布的熵 + 交叉熵  
因此最小化KL散度等价于最小化p q的交叉熵, 交叉熵比KL散度更好计算  
从另外一个角度上来理解，如果使用传统的平方误差损失的话，得到的代价函数不是一个凸函数，会有很多的局部最优点；而交叉熵函数会得到一个相对更加平滑的代价曲线。  
KL散度表示分布之间的定量区别, 可以用于GAN的分布估计, 交叉熵描述了分布之间的联系   

##### (4) 深度学习模型压缩和优化加速方法？
a. 前端压缩: 不会改变原始网络结构的压缩技术 
知识蒸馏, 紧凑的模型结构设计(主要是对神经网络卷积的方式进行改进，比如使用两个3x3的卷积替换一个5x5的卷积、使用深度可分离卷积等等方式降低计算参数量), 滤波器层面的剪枝(主要是对较小的权重矩阵整个剔除，然后对整个神经网络进行微调)
b. 后端压缩: 会大程度上改变原始网络结构的压缩技术
低秩近似(对于复杂网络，权重矩阵往往非常大，非常消耗存储和计算资源。低秩近似就是用若干个低秩矩阵组合重构大的权重矩阵，以此降低存储和计算资源消耗), 未加限制的剪枝(非结构化剪枝和结构化剪枝。非结构化剪枝是对神经网络中权重较小的权重或者权重矩阵进行剔除，然后对整个神经网络进行微调；结构化剪枝是在网络优化目标中加入权重稀疏正则项，使部分权重在训练时趋于0), 参数量化, 二值网络
c. 优化加速: FFT计算Conv2d

##### (6) C++中的List, Vector, Map, Set区别？
List封装了链表,Vector封装了数组, list和vector的最主要的区别在于vector使用连续内存存储，支持[]运算符（下标运算符），而List是以链表形式实现的，不支持[]。  
Map,Set介绍: 它们属于标准关联容器，都是由红黑树实现，他的插入删除效率比其他序列容器高是因为不需要做内存拷贝和内存移动，而直接替换指向节点的指针即可。  
Map和Hash_Map的区别是Hash_Map使用了Hash算法来加快查找过程，但是需要更多的内存来存放这些Hash桶元素，因此可以算得上是采用空间来换取时间策略。  
set为什么不包含重复的元素？ 因为set在添加元素的时候，实际中调用的是map的方法，而因为map中的key是不允许重复的，所以set中的元素不能重复。  

##### (7) LDA(Linear Discriminant Analysis，线性判别分析)和PCA的区别？
见supervised.md


##### (8) ROC和AUC指标理解以及如何画ROC曲线？PR曲线理解, 如何画PR曲线
ROC全称是“受试者工作特征曲线”（Receiver Operating Characteristic）  
ROC曲线的面积就是AUC（Area Under Curve）  
AUC用于衡量“二分类问题”机器学习算法性能（泛化能力）  
将score从大到小排序，每次选取不同的threshold，得到一组FPR和TPR，即ROC曲线上的一个点，将多个这样的点连成线就是ROC曲线。  
ROC只有大于y=x的直线才是有意义的, 否则应该反向预测; ROC中越靠近左上角的模型越好  
为什么使用ROC和AUC作为评价指标？  

因为ROC曲线有个很好的特性：当测试集中的正负样本的分布变换的时候，ROC曲线能够保持不变。在实际的数据集中经常会出现样本类不平衡，即正负样本比例差距较大，而且测试数据中的正负样本也可能随着时间变化(例如样本分布从P, N变为了P, 10N)， 但是ROC还能基本保持不变
ROC: 横轴FPR=FP/(FP+TN), 纵轴TPR=TP/(TP+FN), FPR只跟负样本有关, TPF只跟正样本有关, 正负样本之间没有交叉计算, 改变正负样本的比例并不会改变模型对于正负样本的判断, 因此ROC会保持稳定  

PR曲线纵轴为Precision=TP/TP+FP, 横轴为Recall=TP/TP+FN, 把score从大到小排序, 每次选取不同的threshold, 计算precision, recall, PR曲线越接近右上角的模型越好, PR曲线有正负样本的交互, 对于样本分布变化比较敏感; 当正负样本比例失调时，则ROC曲线变化不大，此时用PR曲线更加能反映出分类器性能的好坏.

##### (9) 逻辑回归LR与SVM的区别？  
a. LR： y^ = sigmoid(\sum w_i* x_i), 交叉熵损失函数(伯努利分布), 基于概率论, 也可以使用最小二乘(均方误差, 高斯分布), 一般不最小二乘法因为求导后交叉熵y/y^, 概率越接近其值越接近1  
b. SVM: 基于几何间隔最大化, hinge loss = 1/2||w||^{2} + \sum a_i y_i(w^T * x_i +b), KKT条件求解, 带入hinge loss中, 转化为只依赖于支持向量的模型(只依赖于w_T x_i + b = 1或-1), 然后使用SMO， 选择两个变量a_i, a_j, 固定其他变量, 将a_j用a_i表示, 优化a_i, 代回求a_j  
c. LR可以产生概率, SVM不能产生概率  
c. LR对异常值敏感，SVM对异常值不敏感: 支持向量机只考虑局部的边界线附近的点，而逻辑回归考虑全局。LR模型找到的那个超平面，是尽量让所有点都远离他，而SVM寻找的那个超平面，是只让最靠近中间分割面的那些点尽量远离，即只用到那些支持向量的样本。因此支持向量机改变非支持向量样本并不会引起决策面的变化，而逻辑回归中改变任何样本都会引起决策面的变化。  
d. 计算复杂度不同, 对于海量数据，SVM的效率较低，LR效率比较高  
e. SVM的损失函数就自带正则项, 是结构风险最小化, LR是经验风险最小化, 如果需要正则项， 必须手动添加  
f. 对非线性问题的处理方式不同, LR主要靠特征构造，构造二阶交叉特征, 然后one-hot离散化, 一般不用核函数。SVM也可以这样，还可以通过kernel(因为只有支持向量参与核计算,计算复杂度不高)。(由于可以利用核函数，SVM则可以通过对偶求解高效处理。LR则在特征空间维度很高时，表现较差。)  
g. 为什么SVM要转换成对偶问题求解？  
使用对偶问题更容易求解；通过对偶问题求解出现了向量内积的形式，从而能更加自然地引出核函数。  

##### (10) KMeans与KNN的区别？  
K-Means是无监督学习的聚类算法，没有类别输出, 只有判别为哪个聚类中心；而KNN是监督学习的分类算法，有对应的类别输出   
KNN基本不需要训练，需要保存所有类别。而K-Means则有明显的训练过程，找到k个类别的最佳质心，从而决定样本的簇类别。   
手肘法: 误差平方和

##### (11) 梯度下降法和牛顿法区别？  
优化 f(x)  
梯度下降 x_new = x_old - lr * f'(x)  
牛顿法 f(x)在x0处的切线为: f(x) - f(x0) = f'(x0)(x-x0)   
该切线在x轴的交点为: x = x0 - f(x0) / f'(x0)  
迭代计算即为牛顿法, 又称切线法  
      
实际应用时使用牛顿法用来计算f'(x) = 0, 求得导数为0的点即为极小值  
f'(x) = f'(x0) + f''(x0)(x-x0)  
x = x0 - f'(x0) / f''(x0)  
即为二阶方法

##### (12) SGD/AdaDelta/Adam优化方法的区别？  
见optimizer.md, https://www.cnblogs.com/guoyaohua/p/8542554.html

##### (13) 目标检测里的hard negative mining做法？
a. Faster RCNN选择与gt_box的IoU大于0.7和小于0.3的proposal分别作为正负样本来训练RPN，但是选择大于0.5和大于0.2且小于0.5的roi分别作为正负样本来训练Fast是一种hard example mining的做法
b. Focal Loss？
L_cross = - \sum(ylogy^ + (1-y)log(1-y^))  
L_focal = -α(1-y^)^{γ}logy^             y = 1  
          -(1-α)(y^){γ}log(1-y^)        y = 0  
α=0.25, γ=2,  α为平衡因子，用来平衡正负样本本身的比例不均衡  
y^){γ}的作用就是当y^越接近y, 那么他在loss中的比例就应该越小, 从而重点学习那些学的不好的样本  

c. OHEM: Online Hard Example Mining  
在Faster RCNN中计算RoIs的时候，我们对每个RoI的loss从大到小排序，选择前N个RoIs样本反向传播  
但是位置相近的ROI在map中可能对应的是同一个位置，loss值是相近的，所以如果直接按照loss对roi进行排序的话，选出来的很可能是靠的很近的一些rois，所以针对这个问题，提出的解决方法是：对hard做nms，然后再选择B/N个ROI反向传播，这里nms选择的IoU=0.7  


##### (14) resnet和densenet为什么可以这么深？
a. 层叠过多的卷积层会出现梯度消失(模型退化), BN通过规范化输入数据改变数据分布，在前传过程中消除梯度弥散
b. resnet的短路连接/shortcuts/skip connection则能在反向传播过程中更好地把梯度传到更浅的层次中。
c. 而DenseNet更为极端，它的skip connection不仅仅只连接上下层，直接实现了跨层连接，每一层获得的梯度都是来自前面几层的梯度加成。

##### (15) densnet效果为什么比resnet效果好？
a. ResNet连接方式可能会阻碍信息的流动，但是DenseNet每层的输出都和最终的输出直接相连，梯度可以直接从末端流到之前的所有的层。
b. DensetNet连接有正则化的作用，可以减少过拟合。
c. DenseNet直接concat不同层的特征图，而不是像ResNet一样element-wise sum，这样每一层增加很少的k个Feature maps就可以使得feature map快速增长。(k称为增长系数)，这称之为“特征重用”，减小参数量和计算量。

##### (16) 常用CNN分类网络简介？
AlexNet: AlexNet引入了Relu和dropout, 引入数据增强、池化相互之间覆盖，卷积池化全连接层
VGG: 整个网络都使用了同样3 * 3大小的卷积核尺寸和2 * 2最大池化尺寸, 2个3 * 3=1个5 * 5
GoogleNet: Inception模块->将1x1，3x3，5x5的conv和3x3的pooling，stack在一起，一方面增加了网络的width，另一方面增加了网络对尺度的适应性  
两个3 * 3的conv代替模块中的5 * 5，降低了参数量的同时，加速计算  
7 * 7的卷积变成了1 * 7和7 * 1的两层串联，3 * 3的也一样，变成了1 * 3和3 * 1，这样加速了计算，还增加了网络的非线性，减小过拟合的概率  

##### (17) Inception-ResNet-V2和ResneXt模型的优势及对比？
ResNeXt是在resnet中加了inception结构, 增加宽度；而Inception-ResNet-V2花式结构真多，是在Inception中加了renset的结构


##### (18) GPU显存占用量计算？ CNN所需要的计算力（FLOPs）和参数量（Parameters）？

显存占用 = 模型显存占用 + batch_size × 每个样本的显存占用  
Linear(M->N): 参数数目：M×N + N (weight + bias)
Conv2d(Cin, Cout, K): 参数数目：Cin × Cout × K × K + Cout
BatchNorm(N): 参数数目： 2N +2N (mean + var + weight + bias)
Embedding(N,W): 参数数目： N × W, 没有bias

FLOPs把一次乘法或者一次加法考虑为一次计算, 所有的乘法次数和加法次数加起来就是FLOPs
Parameters计算方法看上面

##### (19) 深度学习上采样技术
a. unpooling 补0  
b. upsample 补相同的数字  
c. 双线性插值  
d. 反卷积/转置卷积: 可以恢复feature map尺寸用在FCN中, padding+卷积从而使得feature map变大
e. pixel shuffle: 主流应用超分辨率重建, GAN  
先通过卷积获得r^2个通道的特征图（特征图的大小和低分辨率图片的大小一致），然后经过周期筛选（Periodic Shuffing）得到高分辨率的图像。即将shape为(1, r^2C, H, W)的tensor reshape为(1, c, rH, rW), r为放大因子  
周期性筛选: 假如有9个channel, 那么将每个channel的最左上角的元素拼成一个3*3的格子, 然后其他依次类推(类似于3*3卷积变成1个像素的反操作)

##### (20) BN, LN(Layer Norm), IN(Instance Norm),GN (Group Normalization)区别?  
a. BN是取不同样本的同一通道做归一化；[NHW]    
b. LN是取同一样本的不同通道做归一化；[CHW]: RNN作用明显, 还用在Bert里面  
c. IN是取同一样本的同一通道做归一化；[HW]: 风格迁移用的多, 因为图片生成的结果主要依赖于某个图像实例  
d. GN是取同一样本的部分通道做归一化；  

##### (21) multi-label classification的方法以及评价指标？  
mAP：按照score排序，在每一个recall计算precision，然后求平均值  
CP: 把测试样本的预测结果都保存下来, 分别计算每个类别的Precison再平均80个类别  
OR: 统计所有类别的Precision 

##### (22) 图像腐蚀膨胀的原理？
用结构元素B扫描图像A，腐蚀和膨胀分别是与图像做“与”，“或”运算  

##### (23) CNN感受野计算？
l_k = l_{k-1} + [(f_k - 1) * s1 * s2 * ... s_{k-1}]
l_k为第k层感受野, f_k为第k层filter尺寸, s_i为第i层stride, 空洞卷积相当于卷积核dialate, 按照dialate后的filter大小计算

##### (24) 语义分割模型的评价指标PA,mPA,mIoU？
PA: pixel accuracy, 分对的像素总量除以像素总数
mPA: mean pixel accuracy, 先对每个类计算PA，然后再对所有类的PA求平均
mIoU(Mean Intersection over Union, 平均交并比): 分别对每个类计算（真实标签和预测结果的交并比）IOU，然后再对所有类别的IOU求均值

##### (25) 均值滤波；中值滤波；高斯滤波去噪声？
噪声分类：椒盐噪声(幅值基本相同，但出现位置随机);高斯噪声(幅值大小符合某一分布)  
均值滤波：对于当前处理的像素，选择其周围像素(模板)的均值来代替当前像素值
中值滤波：周围像素由小到大排序之后，选择中值来代替原像素
高斯滤波：用一个模板（或者称为卷积，掩膜）扫描图像中的每一个像素，用模板确定邻域内的像素的加权平均(核函数高斯函数)值替代中心像素值  

##### (26) 目标检测中如何解决目标尺度不一致的问题？
a. 不同尺度的feature map上生成proposal和multi-scale training 和multi-scale testing
另外见: https://zhuanlan.zhihu.com/p/50621694

##### (27) SENet? Non-local?

##### (28) SVD?
X = U∑V^T, U^{T}U=I, V^{T}V=I  
A^{T}A的特征向量拼成V, AA^{T}的特征向量拼成U, 奇异值=sqrt(特征值), 通过特征值/向量阶段可以实现降维目的  
X = U∑V^T  
X^T = V^{T}∑U  
X^{T}X = V(∑^2)V^{T}  
V^{T}X^{T}XV = ∑^2, 所以V是X^{T}X的特征向量矩阵, 且其特征值为∑^2对角线上元素  

##### (29) 图像检索常见Trick
a. DBA, QA(database augmentaton, query expansion)  

b. diffusion?  

c. ANN? 局部敏感哈希,   
d. KD tree: 用于实现knn算法    
构建: KD树本身是一个二叉树, 用于对T个k维的数据点进行knn搜索, 首先选取一个包含所有数据点的超矩形区域, 选取坐标轴x^l, l = j%k + 1, 其中j为二叉树深度, 选取x^l轴的中位数, x^l = median将空间划分为左右两个矩形, 然后继续递归的进行划分   
使用:   
a. 从根节点出发递归地找到包含当前节点的叶子节点, 当前节点和待查询节点比较, 若比较坐标轴上小于当前节点, 则左子树, 否则右子树; 把该叶子节点作为当前
近似最近邻  
b. 查找节点一定位于当前节点的一个子节点对应的区域内  
检查当前节点的父节点的 另外一个叶子节点区域中, 是否有离查找节点更近的点, 即检查另一区域是否与以查找点为球心, (近似最近邻-查找点)为半径的圆相交, 若
相交则可能存在最近邻, 向下递归; 若不存在, 向上递归  
c. 回退到根节点, 并尝试继续回退时, 搜索结束  
e. NSG(Navigating Spreading-out Graph):    

##### (30) DeepWalk, LINE、Node2Vec
1. DeepWalk: 通过随机游走的方式，将图结构数据转化为了自然语言处理的任务来完成  
a. 从每个结点出发n_walks次，每一步都采取均匀采样的方式选择当前结点的邻接结点作为下一步的结点随机游走。当游走的路径长度达到walk_length后，停止一次游走。这样就生成了一个个游走的序列  
b. 每个walk都被当成Word2Vec中的一个句子，而每个结点都是Word2Vec中的一个词; 之后采用word2vec的skip-gram算法, 使用一个大小为window_size的滑动窗口作为一条walk的context，使用一个context中的中心词去推测所有context中的其他词，使用的目标函数也与Word2Vec一致 

2. LINE: 认为随机游走不考虑边权, 而且全部展开开销太大, 所以在图上定义了两种相似度——一阶相似度与二阶相似度  
一阶相似度: 邻居节点的边权决定了一阶相似度, 实际一阶相似度为邻域边权和的归一化(w_{ij} / W), embeeding学习一阶相似度为节点内积+sigmoid, 最小化实际相似度与学习相似度之间的KL散度  
二阶相似度: 邻居的相似程度决定了二阶相似度, 实际的二阶相似度p(v_j|v_i) = w_{ij} / d_i, w_{ij}为边ij的权, d_i为i节点的出度, embedding学习的二阶相似度为节点内积在邻域上的softmax, 再求两种相似度之间的KL散度  

3. Node2Vec: 基于DeepWalk的延伸工作，它改进了DeepWalk随机游走的策略, 希望更好地保留网络的结构信息  
a. 让同一个社区内的结点表示能够相互接近: 广度优先搜索->广度优先游走策略相反将会促进游走不断的回头，去访问上一步结点的其他邻居结点  
b. 在不同社区内扮演相似角色的结点表示也要相互接近: 深度优先搜索->深度优先游走策略将会限制游走序列中出现重复的结点，防止游走掉头，促进游走向更远的地方进行  
c. 通过超参数p, q来控制网络的搜索策略, 生成walk序列  
下一步的搜索概率alpha: 1/p(下一个节点采样当前节点), 1(下一个节点采样直连节点), 1/q(下一个节点采样间接连接的节点, 即两跳节点)  
p为保守探索系数, 倾向于访问原有的节点, q为激进探索系数, 倾向于访问更远的节点, 调整p, q来调整探索策略  
实际时, 使用p_{ij} = alpha * w_{ij} / Z, 考虑了边权系数, 并在邻域出度节点上进行归一化  

4. SDNE: 通过深度自编码器直接把一阶和二阶相似度保存在embedding中

##### (31) KL散度, JS散度, Wasserstein距离(推土机距离)
Wasserstein距离: 再来看式子，∏(Pr, Pg)代表对于(x,y)的边缘分布为Pr和Pg的联合分布的集合。我们从这个集合里面任选一个联合分布r，对应这个r联合分布，求出(x,y)服从r这个分布时x，y两个点对于||x-y||的期望值。对于联合分布集合里面所有的联合分布，我们都能求出这样一个期望值，其中最小的那个期望值就是我们要求的wasserstein-1 距离了。

##### (32) Dropout，dropout相当于传统机器学习中的什么?
bagging

##### (33) L1, L2说一下
L1 lasso, 高维超平面, 稀疏, L2 ridge, 超球, 均匀稠密

##### (34) 决策树: 划分终止条件, 某个节点上某一类别属性值完全相同, 或者达到叶子节点分裂的最大数目
a. 分类树: 穷举每一个类别特征的每一个阈值, 计算熵/增益率/基尼系数, 然后进行节点划分
ID3: 信息熵最大: 划分后节点的信息熵 - 划分前节点的信息熵  
C4.5: 信息增益率最大  
CART: 基尼系数  
b. 回归树: 每一个节点都会得到一个预测值, 某类别的预测值为该节点下所有数据该类别的平均值  
但是划分节点与分类树不同: 穷举每一个类别的每一个阈值，计算均方误差，选取均方误差最小的作为划分依据

##### (35) 介绍一下GBDT,XGBOOST, LightGBM, 区别? GBDT原理，是回归树还是分类树? GBDT跟XGBoost对比?XGBoost怎么并行化 
1) AdaBoost:   
a. 初始化数据集权重为均匀权重w_{i} = 1/N, 使用带权数据学习第m个基分类器, 计算分类误差率e_{m} = sum(w_{i}I(G(x_i) = y_i)), 分类器权重系数  
a_{i} = 1/2 log((1-e_{m}) / e_{m}), 更新数据集权重分布w_{i}^{new} = w_{i}^{old} e^{-a_{m}y_{i}G(x_i)}, 如果预测相同权重系数为  
w_{i}^{old} e^{-a_{m}}, 权重变小, 否则权重变大(注意权重还要归一化)  
b. 最终分类器f(x) = sum(a_{m}G_{m}(x)), 多分类器线性加权和  
c. 损失函数: Adaboost对应着指数损失函数的可加模型  
L_{m}  = sum_{i=1}^{N} (e^{f(x_{i}) * y_{i}})  
L_{m+1}= sum_{i=1}^{N} (e^{f(x_{i} + a_{m+1}G_{m+1}(x_{i})) * y_{i}})    
L_{m+1}= sum_{i=1}^{N} (e^{f(x_{i}) * y_{i}}  * e^{-a_{m}G_{m+1}(x_{i})y_{i})} ), 后半部分即为新增树的系数  


2) GBDT: Gradient Boosting Decision Tree, 梯度提升决策树  
a. 对于数据(x_1, y_1), (x_2, y_2), ..., (x_N, y_N), 已有的一个树模型F(x), r_i = y_i - F(x_i)为关于x_i的残差, 学习一个新的树模型h拟合数组(x_1, y_1 - F(x_1)), (x_2, y_2 - F(x_2)), ..., (x_N, y_N - F(x_2)), 则得到更好的分类模型 F + h  
b. 考虑平方和损失函数1/2(y_i - F(x_i))^2, y_i - F(x_i)也是损失函数的负梯度, 所以也就是在使用模型不断地拟合负负梯度, 那么F + h实际上就相当于  
在当前模型上使用负梯度进行参数更新, 即梯度下降法   
c. 但是由于平方和损失函数对于异常点不够鲁棒, 实际使用L1 loss, |y - F(x)|  
d. GBDT是回归树, 因为使用了回归损失  

GBDT+LR: 训练100棵树, 每棵树有64个叶子节点, 那么每个样本就被分类了100次, 每个标签位于0~63, 将分类标签one-hot为64维, 100棵树的one-hot拼接起来为64 * 100的离散特征, 作为LR的输入, 可以用作排序

3) XGBoost
a. 传统GBDT以CART作为基分类器，xgboost还支持线性分类器，这个时候xgboost相当于带L1和L2正则化项的逻辑斯蒂回归（分类问题）或者线性回归（回归问题）  
b. xgboost在代价函数里加入了正则项，用于控制模型的复杂度. 正则项里包含了树的叶子节点个数、每个叶子节点上输出的score的L2模的平方和. 从Bias-variance tradeoff角度来讲，正则项降低了模型的variance，使学习出来的模型更加简单，防止过拟合.  
c. xgboost借鉴了随机森林的做法，支持列抽样.  
d. 并行化: xgboost的并行是在特征粒度上的. 我们知道，决策树的学习最耗时的一个步骤就是对特征的值进行排序(因为要确定最佳分割点)，xgboost在训练之前，预先对数据进行了排序，然后保存为block结构，后面的迭代中重复地使用这个结构，大大减小计算量. block结构使得计算每个特征的每个阈值的增益时, 可以进行  
多线程计算
e. shrinkage,相当于学习速率(XGBoost中的eta). XGBoost在进行完一次迭代时，会将叶子节点的权值乘上该系数，主要是为了削弱每棵树的影响, 相当于渐进递减的学习速率, 使用很多小学习率的提升树来拟合最终的问题  

f. 缺失值处理, xgboost把缺失值当做稀疏矩阵来对待，本身的节点在分裂时不考虑有缺失值的数据, 然后把有缺失值的数据分裂到左子树, 计算损失, 再分到又子树, 计算损失, 选择最优的. 如果训练中没有数据缺失，预测时出现了数据缺失，那么默认被分类到右子树.  
 

4) LightGBM  
LightGBM和XGBoost的决策树生长策略不同
LightGBM: leaf-wise, 不停地找到当前增益最大的节点, 向下生成, 容易生成较深的决策树, 产生过拟合  
XGBoost: level-wise, 逐层生成树节点, 不容易过拟合, 但不加区分的对待同一层的叶子，带来了很多没必要的开销


##### (36) 集成学习(Ensemble Learning)中的bagging算法和boosting算法流程和区别？随机森林是什么?stacking为什么有效?

bagging: 从数据集中有放回采样多次(36.5没采样到), 训练多个决策树, 然后vote  
boosting: 往上看  

随机森林: 以决策树为基学习器+bagging+随机特征选择: 随机选择样本(放回抽样, 行抽样); 随机选择特征(列抽样); 构建决策树(CART树); 随机森林投票(平均)

bagging并行的训练很多的分类器降低了方差, 所以每个基分类器目的是降低偏差, 所以使用很深并且不剪枝的基分类器  
boosting每一轮都会比上一轮更加拟合原始数据, 偏差在降低, 所以要选择方差更小的基分类器, 要求更简单, 树会很浅或者剪枝

假设多个分类器, 均值为u, 方差为v^2, 分类器两两之间相关性为p, 那么sum(x_i)的方差为pv^2+(1-p)v^2/n  
bagging: 多个分类器近似独立, p=0, sum(x_i)均值为u, 方差为v^2/n  
boosting: 分类器是在学习前一个分类器的误差, 那么偏差在渐进降低, 多分类器级联式学习，极端情况下认为p=1, 方差为v^2  
stacking: 数据分k折, 留下一折, 使用其他数据训练模型, 然后多个模型的结果平均, 其实就是在降低模型的方差, sum(x_i)均值为u, 方差为v^2/n    

##### (37) 介绍GCN, GRaphSage, GAT

##### (38) Softmax反向传播的梯度更新公式
sigmoid=>f: f(x)( 1 - f(x) ) 
softmax=>g: g(x)( 1 - g(x) )

##### (39) 介绍一个CV里的经典网络，比如resnet, 讲讲3 * 3,5 * 5,1 * 1卷积

##### (40) Resnet相当于传统机器学习中的什么
softmax是LR在多分类问题上的推广

##### (41) BN在训练和测试的时候的差别
训练的时候学习u, sigma, alpha, beta, 测试的时候直接使用之前学习到的alpha, beta, 以及滑动均值保存的u, sigma, 而不是测试样本重新计算滑动均值

##### (42) LSTM和GRU的区别?
1. GRU参数更少因此更容易收敛，但是数据集很大的情况下，LSTM表达性能更好
2. 从结构上来说，GRU只有两个门(update和reset)，LSTM有三个门(input，output, forget)，GRU直接将hidden state 传给下一个单元，而LSTM则用memory cell把 hidden state 包装起来  
RNN: 
h_t = f(W_{ih}x_{t} + b_{ih} + W_{hh}x_{t} + b_{hh})
o_t = g(W_{ho}h_{t})


LSTM:  
i_t = sigma(W_{ii}x_{t} + b_{ii} + W_{hi}h_{t-1} + b_{hi})  输入门   
o_t = sigma(W_{io}x_{t} + b_{io} + W_{ho}h_{t-1} + b_{ho})  输入门   
f_t = sigma(W_{if}x_{t} + b_{if} + W_{hf}h_{t-1} + b_{hf})  遗忘门  
g_t =  tanh(W_{ig}x_{t} + b_{ig} + W_{hg}h_{t-1} + b_{hg})  遗忘门  
c_t = f_t * c_{t-1} + g_t * i_t                             memory cell  
h_t = o_t * tanh(c_t)                                       hidden state  

GRU:   
r_t = sigma(W_{ir}x_{t} + b_{ir} + W_{hr}h_{t-1} + b_{hr})           reset gate       
z_t = sigma(W_{iz}x_{t} + b_{iz} + W_{hz}h_{t-1} + b_{hz})           update gate  
n_t =  tanh(W_{in}x_{t} + b_{in} + r_t * (W_{hn}h_{t-1} + b_{hn}))   memory  
h_t = (1 - z_t) * n_t + z_t * h_{t-1}                                hidden state    

##### (43) Word2vec: word2vec参数量巨大, 容易过拟合, 把常见词组作为一个单词/减少常见词抽样; 训练缓慢, 使用层次softmax/negative sampling
a. CBOW： 周围词输入预测中心词, one-hot * 输入embedding矩阵, 多个词的均值作为隐层输入, 再乘输出矩阵, softmax预测中心词  
b. skip-gram: 中心词输入, 预测周围词; 构建(中心词, 周围词)的样本对, 统计其概率, 输入中心词, 矩阵变换后softmax预测其样本对概率
###### 从隐藏层到输出的Softmax层的计算量很大，因为要计算所有词的Softmax概率，再去找概率最大的值, hierarchical softmax 和negtive sampling就是用于解决这个问题
c. hierarchical softmax: 首先将所有待分的类别根据词频构建哈夫曼树(词频为权值, 哈夫曼树为带权路径和最小的树, 每个类别都变成了01编码), 然后哈夫曼树的每一个分叉都对应了一个逻辑斯特回归(使用同一个输出向量计算LR), 0向左, 1向右, 树的深度为logN, N为总的类别数, 最终p(w|context)转化成了路径上逻辑斯特回归的连乘  
若某类别(word)w_t, 其哈夫曼编码为code = {1, 0, 1, ..., 1}, x_t为其输出向量  
Loss = sum(log(p(w_t|context)))  
p(w_t|context) = p(c1=1|x_t) p(c2=0|x_t, c1=1) p(c3=1|x_t, c1=1, c2=0) ...  
p(c1|x_t) = sigmoid(w x_t) c1=1, 1 - sigmoid(w x_t), c1= 0  

d. negative sampling: softmax时我们希望目标类别为1, 其他类别都为0, 这些类别就是negative word, 在negative word中采样一部分用于目标word的训练, 使用LR, 考虑样本为{w_t, neg_1, neg_2, ..., neg_N}  
Loss = p(w_t, context) * p(neg_1, context) * p(neg_2, context) * ...  
     = sigmoid(w * x_0) (1 - sidmoid(w * x_{neg1})) * (1 - sidmoid(w * x_{neg2})) * ...  

##### (44) 讲一下Transformer, BERT
Transformer: multi-head self attention, add & layer norm, FFN, add & layer norm
BERT:  双向transformer, 预训练任务: a. mask词然后预测; b. AB句子, 判断B是否是A的下一句
OpenAI GPT: 受限transformer, 只处理当前词左侧的词  
ELMo: 经过独立训练的从左到右和从右到左LSTM的串联  
只有BERT是双向的上下文信息

##### (45) 讲一下HMM, CRF（隐马尔科夫模型, 条件随机场）
1.HMM是生成模型，CRF是判别模型  
2.HMM是概率有向图，CRF是概率无向图  
3.HMM求解过程可能是局部最优，CRF可以全局最优  

##### (53) 用户侧特征稀疏会造成什么情况  
a. embedding的维度很大, 导致embedding占用了很大的空间, 全读进来再进行look-up内存承受不了, 可以考虑对id进行hash或者重编码处理  
b. 对于极其稀疏的user, 可以认为user之间相互无关, 那么很难学习到多user之间的交互信息, 此时embedding学习不准确, LR的记忆性会产生更好的效果  

##### (50) 关于wide and deep的记忆性和泛化性  
a. Wide & Deep 模型的核心思想:  
结合 线性模型的记忆能力 和 DNN模型的泛化能力，从而提升整体模型性能  
b. 记忆性: LR+原始稀疏特征(离散特征/连续特征分桶转离散, 再one-hot)+高阶交叉特征, “记忆”历史数据中曾出现的的特征/特征对  
优点: 模型可解释高，实现快速高效; 缺点: 需要人工设计, 过于细粒度的特征组合会造成过拟合; 泛化能力, 不能处理未出现过的特征/特征对  
c. 泛化性: 为sparse特征学习embedding, 进而捕捉特征相关性  
优点: 需要更少的人工参与. 对于没出现过的特征组合具有良好的泛化能力; 缺点: 当sparse特征极其稀疏时, 如独特爱好的users以及很小众的items, 此时大部分的user-item是无关的, 但是embedding还是会产生非零推荐, 导致泛化到无关物品上, 此时"记忆性"展现出了优势, 因为可以记忆住历史选择  
Memorization根据历史行为数据，产生的推荐通常和用户已有行为的物品直接相关的物品. 而Generalization会学习新的特征组合，提高推荐物品的多样性.  
d: wide: LR=>sigmoid(原始特征, 高阶特征)  
deep: 为sparse特征学习embedding, 然后MLP   
wide&deep: 网络会对一些sparse特征(如ID类特征)学习一个低维的dense embeddings(维度量级通常在10~100), 输出为
sigmoid(w_{wide}^T x_{wide} + w_{dense}^T x_{dense} + b)
e: 联合训练和集成是不同的，集成是每个模型单独训练，再将模型的结果汇合. 集成的每个独立模型都得学得足够好才有利于随后的汇合，因此每个模型的model size也相对更大. 而联合训练的wide部分只需要作一小部分的特征叉乘来弥补deep部分的不足，不需要一个full-size 的wide 模型.

##### (51) 说下为什么广告里面特别喜欢用id类特征，而数据挖掘不喜欢用（从泛化性和记忆性说下）
广告类需要记忆性? 数据挖掘对于没见过的数据需要泛化性？

##### (54) 说说one-hot为什么有效，尤其对于LR来说
a. one-hot编码后离散特征的取值映射到了欧式空间, 距离的计算更加合理(欧氏距离/余弦距离)  
b. one-hot可以处理离散特征，也可以处理连续特征(分桶处理为离散特征，再转one-hot)  
c. one-hot的形式可以更简单的构造高阶交叉特征, 从而提取高阶相似性, 补充LR只能进行线性组合的短板, 提升性能  
d. one-hot计算速度比dense快  
e. 特征由离散变量到one-hot相当于非线性映射
f. one-hot离散化之后对于异常值更鲁棒

##### (41) DeepCTR框架?
集成了Wide&Deep, DeepFM算法

##### () 推荐系统召回和排序
推荐系统步骤: 召回, 粗排, 精排, rerank  
a. 召回阶段: 数据量巨大, 速度要够快, 模型不能太复杂，特征较少(百万级), FM, FFM, DNN等均可用于召回  
多路召回融合: (缺点是每路召回都有截断需要手调), 送入排序模型中, 可以分非个性化召回: 历史记录, 热门等, 以及个性化召回: 兴趣标签, 协同(标签)召回  
模型代替多路召回, 核心思想是: 将用户特征和物品特征分离, 在线上(test)时, 根据user embedding使用faiss等快速检索item embedding进而进行推荐. “双塔”模型指的其实是用户侧和物品侧特征分离学习Embedding的结构(缺点, 召回头部内容问题, 召回物品可能总是物品较多的几个头部领域, 缺乏多路召回互补的多样性, 解决办法: 头部领域降采样, 鼓励模型具有多样性等)  
b. 排序阶段: 数据里较少, 模型要够准, 可以使用复杂模型、复杂特征(百级别), LR, FM, DeepFM, Wide&Deep  
c. 多阶段训练问题: 各个阶段独立训练, 然后进行召回-排序时, 需要保证各个阶段训练目标的一致性, 否则会出现排序的高质量商品已经在召回被过滤的情况  

##### (47) 排序阶段模型
a. FM（因子分解机）: y = w_0 + sum_{i=1}^{n}(w_i * x_i) + sum_{i=1}^{n}sum_{j=i+1}^{n}(<v_i, v_j> x_i * x_j)  
<v_i, v_j>是为了每一个x_i, x_j学习的一个embedding的内积, 如果把<v_i, v_j>替换为w_{ij}, 那么如果训练数据中没有出现过x_1, x_3的特征组合, w_{13}的权重就是0, 模型只有记忆性没有泛化性, 将w_{ij}变为向量内积之后, 即使x_1, x_3没有同时出现过, 只要x_i, x_j出现过样本, 那么他们就有自己的embedding, 所以还是可以进行计算这个特征组合的权重, 泛化性强;  
b. MF(矩阵分解): 现有M = (user, item)的稀疏矩阵, 表示用户对于某些商品的评价分数, 希望预测出某个用户对于某一个未知的商品的评价分数, 希望进行如下矩阵分解: M = U I^T, U = (user, embedding), I = (item, embedding), 所以我们求解Loss = sum(m_{ij} - u^T * i), 求导通过梯度下降更新u, i, 实际使用时u, i也可以加入l2正则化, 矩阵分解对于小规模推荐系统效果还可以, 大规模效果不太好    
c. FFM: 引入域的概念  
y = w_0 + sum_{i=1}^{n}(w_i * x_i) + sum_{i=1}^{n}sum_{j=i+1}^{n}(<v_{i, f_j}, v_{j, f_i}> x_i * x_j)  
<v_i, v_j>改为<v_{i, f_j}, v_{j, f_i}>, v_i要使用对应的f_j域对应的embedding, 将多个域分开, 参数量变大, 增强拟合能力  
d. DeepFM: 与Wide&Deep模型结构相同, Wide部分使用FM，FM和Deep部分共享embedding, FM学习一阶和二阶特征, Deep学习高阶特征, 相比Wide&Deep不需要手动特征工程   
e. DIN(Deep Interest Network for Click-Through Rate Prediction):  
现在有用户的行为序列, 希望预测用户的下一次点击的商品, 输入有user feature: good_id, shop_id, 待匹配的有ad feature: good_id, shop_id, other_id   
V_ua = sum_{i=1}^{n}w_i V_i = sum_{i=1}^{n} g(V_i, V_a)V_i, V_i为用户的第i次行为的embedding, V_a为第a个商品的embedding, V_ua为user在第a个商品下的embedding  
对学习到的商品embedding进行二维可视化, 发现用户的兴趣是多峰的, 即存在多个明显的聚类中心;  
用户的兴趣不是一个点, 而是一个多峰的函数, 而且当候选广告发生变化的时候, 这个兴趣函数也在变化着;  
f: DIEN(Deep Interest Evolution Network for Click-Through Rate Prediction):  
用户的兴趣是不断进化的，而DIN抽取的用户兴趣之间是独立无关联的，没有捕获到兴趣的动态进化性; 通过用户的显式的行为来表达用户隐含的兴趣，这一准确性无法得到保证.  

##### (48) 召回阶段模型: 只要能够学得embedding的模型, 理论上都可以用作召回/排序, 看速度的权衡  
a. FM召回:  FM也可以用作召回, 把离线计算的embedding保存下来, 然后embedding内积就可以计算相似度   
b. DNN双塔召回: 起源于DSSM， 微软发布的用于query/ doc的相似度计算模型, embedding算余弦相似度然后softmax  
双塔其实就是一个塔user embedding, 一个塔item embedding, 然后双塔做内积, user embedding在测试时实时计算, item embedding提前计算然后保存下来, 对于一个query, 转化成了item embedding的检索问题  
c. 用户行为序列做召回: GRU, Transformer, RNN等把用户行为序列转化为embedding, 然后与item embedding混合做分类或检索来进行召回  
d. 用户多兴趣拆分(MIND: Multi-Interest Network with Dynamic Routing for Recommendation at Tmall):  
e. TDM深度匹配树做召回

XDL, Euler?

##### (49) 讲一下多任务学习?  
a. ESSM(Entire Space Multi-Task Model: An Effective Approach for Estimating Post-Click Conversion Rate)  
解决CVR预估面临的 数据稀疏 以及 样本选择偏差 这两个关键问题
1) 样本选择偏差: 转化是发生在点击之后的, 传统CVR以点击数据为训练集，转化为正样本，未转化为负样本；但是真实情况下是在完整空间下进行测试，即包括点击与未点击，因此数据分布存在偏差  
2）CVR步骤发生在点击后，其训练数据比CTR更为稀疏  
CTR(所有训练数据, 点击/未点击)，CVR(所有点击数据, 转化/未转化)， CTCVR是三个不同的任务，点击率高不一定转化率高，转化率高也不一定点击率高，他们是一个序列，需要点击->转化, 所以我们之前训练的CTR实际上是CTCVR  
p_{CTCVR}(z=1, y=1, |x) = p_{CVR}(z=1|y=1, x) * p_{CTR}(y|x=1)  
所以构造双路并行模型, 一路为CVR(主路), 一路为CTR(支路), 两路共享embedding, p_{CVR} * P_{CTR} = p_{CTCVR}，loss中为CTR & CTCVR的交叉熵加和, 可以用全部数据训练CTR, 用点击数据训练CTCVR, 从而隐式地学习CVR  
p_{CTCVR} = p_{CVR} * P_{CTR}， 也可以用p_{CVR} = p_{CTCVR} / P_{CTR}, 但是除法容易导致数值不稳定  

b. MMOE(Modeling Task Relationships in Multi-task Learning with Multi-gate Mixture-of-Experts)  
ESSM中对于CTR, CVR使用了shared bottem, 但是CTR, CVR是两个高度相关的任务，如果任务之间的的差异的影响  
多任务学习范式:   
ESSM: input => shared bottem                                       => 分出两个支路分别做多任务学习  
MMOE: input => multi expert(neural network), 门控融合(多个门系数和为1, 门控可以共享多个expert权重, 也可以每个任务学习一个门控) => 分出两个支路分别做多任务学习


##### (52) 协同过滤
基于内容的过滤: 根据物品内容或者元数据, 发现物品或内容的相似性, 基于用户历史行为进行推荐
基于协同过滤的推荐:  
a. 基于用户的协同过滤(User-based Collaborative Filtering): 与目标用户有相同喜好的邻居，然后根据目标用户的邻居的喜好产生向目标用户的推荐; 
b: 基于项目的协同过滤(Item-based Collaborative Filtering): 根据用户的信息或者评价, 发现物品和物品之间的相似度，然后根据用户的历史偏好信息将类似的物品推荐给该用户
c: 基于模型的协同过滤推荐(Model-based Collaborative Filtering): 根据用户数据, 训练一个推荐模型, 生成推荐数据



##### graph embedding做召回
利用图上节点的异质性, 为user, item分别学习embeding, 实际使用时可以用embedding的内积做召回

##### 冷启动策略有哪些?  
用户冷启动:   
a. 提供非个性化的推荐, 如推荐热门, 快速试探随机推荐, 然后根据点击反馈做调整   
b. 利用用户注册时提供的信息  
c. 主动构造选项测试用户兴趣  
e. 利用其它app沉淀的信息推荐   

系统冷启动:  
a. 用户注册信息   
b. 用户兴趣  
c. 热门内容  

物品冷启动:
a. 利用物品的meta data  
b. 快速试探策略  
c. 和其他物品的内容相似性  

##### 如何评估冷启动
A/B测试
广告指标评估: CTR(实际点击次数/展示次数)，CVR(转化量/点击量)  
搜索指标评估: item点击数/曝光数, 点击user数/曝光数, 搜索内容总的点击数, 搜索内容总的点击用户数

##### 样本不均衡解决办法  
当正样本很少，负样本很多时，如果不进行采样，那么模型就算准确率很高，也有可能是对于负样本大量拟合得到的  
a. 样本采样, 欠采样较多样本/过采样较少样本, 过采样: SMOTE, 选取样本最近邻, 二者连线上随机选取一个样本作为扩充样本  
b. 改变样本的权重系数(loss内)  
c. focal loss等hard mining的方法
d. AUC会对于正负样本的分布变化总体保持稳定
e. 过/欠采样后，分布会产生偏移, 影响分类器的边界


##### 数据抽样算法:   
a. 蓄水池抽样, 适用于海量数据随机抽样  
先初始化一个集合，集合中有k个元素，将此集合作为蓄水池。然后从第k+1个元素开始遍历，并且按一定的概率替换掉蓄水池里面的元素  
将前k个数取出来放入结果集中，然后从第k+1个数开始遍历。假设遍历到第i个数，以ki的概率替换掉蓄水池中的某个元素即可  
b. 分层抽样  
分层抽样是指在抽样时，将总体分成互不相交的层，然后按照一定的比例，从各层独立地抽取一定数量的个体，将各层取出的个体合在一起作为样本的方法  

##### 神经网络参数初始化为0?逻辑回归参数初始化为0?
a. 神经网络参数初始化为0:  
假设一个三层的神经网络, 输入为x1, x2, x3, 中间层y1, y2, 输出为z, 权重分别为w11, w12, w13, w21, w22, w23, w4, w5  
y1 = f(w11 * x1 + w12 * x2 + w13 * x3) = f(0)  
y2 = f(w21 * x1 + w22 * x2 + w23 * x3) = f(0)   
z = f(w4 y1 + w5 y2) = f(0)  
Loss = 1/2 (y - z)^2  
Loss对w4求导: (y-z) f'(0) y1 = (y-z)f'(0) f(0)  
w5的导数与w4相同, 同理可得同一层的每一个权值导数都相同, 没有任何鉴别力了  
b. y = f(sum(w_i * x_i)), y' = f' * x_i, 当w_i为0时, f' = y(1-y) = 0.5 * (1 - 0.5)不为0, 梯度更新没问题


##### 多峰问题



介绍一下多态
python的字典是如何实现的: 哈希计算索引, 存在对应位置的数组上
如何解决哈希冲突
graph embedding中如何做负采样
python迭代器和生成器的区别
LDA和SVD有什么联系

##### (54) n-gram https://zhuanlan.zhihu.com/p/32829048; word2vec: CBOW/skip-gram


##### (55) TF-IDF: term frequency–inverse document frequency, 词频-逆文档频率(log)

##### (56) 布隆过滤?
n长度二进制数组, k个哈希函数, 哈希算索引将数组位上置1, 用于海量数据查询

##### (35) 海量数据前k大
1. partition
2. k-multiset

##### (57)  怎么改善用户搜索后显示的内容的一个排序质量？说说有什么特征可以构建，用什么模型？

##### (58) 单调递增数组，尽可能想一些方法将它们压缩


##### (39) 数据中有噪声如何处理？


##### 哪些场景下的分类问题不适用于交叉熵损失函数？
hinge loss: max(0, 1 - y(wx+b)), wx+b > 1时损失才为0, 有margin为1的惩罚, 对wx+b提出了更高的要求, 不仅仅是sigmoid(wx+b) > 0.5  
cross entropy只是对于概率的拟合, 没有考虑到输入x的margin性质, 也就是样本的稀疏性, 特异性, 当希望这种性质的时候, margin-based loss更有效  
cross entropy的样本分布是围绕圆点的射线, 加入triplet/center loss后变为一团一团的聚类  


##### (24) 语义分割网络FCN、UNet、ENet的特点？

##### (25) 轻量化网络MobileNet and ShuffleNet?

##### (24) SIFT、HOG、Canny算子的原理？

##### (18) GAN的目标函数及其和交叉熵的区别？CycleGAN原理简介？其他GAN?

##### 图像融合泊松blending原理？

##### PCA白化和ZCA白化（Zero-phase Component Analysis Whitening）白化的区别？

##### cross entropy，logistic loss 和 KL-divergence的关系和区别？

##### 为什么GAN的generator比discriminator更难训练？

##### (5) YOLO系列

##### 风格迁移中的Gram矩阵?

##### np实现CNN？实现maxPooling?

##### 改进的softmax损失函数有哪些？
cosFace:  
arcFace:  

##### label smoothing 和 mixup如何实现？


##### relu为什么可以防止梯度消失？为什么正则化可以防止过拟合？

##### EM（Expectation Maximization，最大期望算法）

##### DBCAN（Density-Based Spatial Clustering of Applications with Noise，具有噪声的基于密度的聚类方法）


##### 介绍C++的虚函数
C++多态(polymorphism)是通过虚函数来实现的, 声明基类的指针，利用该指针指向任意一个子类对象，调用相应的虚函数，动态绑定. 

##### 析构函数一定要是虚函数吗?  
C++类有继承时，析构函数必须为虚函数;  
a. SubClass* pObj = new SubClass();  delete pObj; 直接创建子类指针  
不管析构函数是否是虚函数(即是否加virtual关键词)，delete时基类和子类都会被释放;  
b. BaseClass* pObj = new SubClass();  delete pObj; 创建父类指针, 指向子类对象  
若析构函数是虚函数(即加上virtual关键词)，delete时基类和子类都会被释放;  
若析构函数不是虚函数(即不加virtual关键词)，delete时只释放基类，不释放子类;  

##### 虚函数表
每个包含虚函数的类都包含的一个虚函数表, 虚表是一个指针数组，其元素是虚函数的指针，每个元素对应一个虚函数的函数指针. 虚表是属于类的，而不是属于某个具体的对象，一个类只需要一个虚表即可。同一个类的所有对象都使用同一个虚表. 为了指定对象的虚表，对象内部包含一个虚表的指针，来指向自己所使用的虚表。为了让每个包含虚表的类的对象都拥有一个虚表指针，编译器在类中添加了一个指针(*__ptr)，用来指向虚表. 这样，当类的对象在创建时便拥有了这个指针，且这个指针的值会自动被设置为指向类的虚表.


##### (30) 异质图神经网络
a. 不同类型节点的异质性(eg. 电影, 演员, 导演)
b. 不同元路径语义的不同(电影1->演员->电影2, 电影1->导演->电影3)
c. 不同邻居的信息融合(电影1->电影2, 电影3)

##### embedding技术应用

##### (31) hadoop经典word count代码逻辑梳理；用hadoop统计100w词语的词频，map/reduce工作原理；
map-reduce分为: input, split, map, shuffle, reduce, output六步  
a. 输入(input)：如给定一个文档，包含如下四行：  
Hello Java  
Hello C  
Hello Java  
Hello C++  
b. 拆分(split)：将上述文档中每一行的内容转换为key-value对，即：  
0 - Hello Java  
1 - Hello C  
2 – Hello Java  
3 - Hello C++   
d. 映射(map)：将拆分之后的内容转换成新的key-value对，即：  
(Hello , 1)   
(Java , 1)  
(Hello , 1)   
(C , 1)  
(Hello , 1)   
(Java , 1)  
(Hello , 1)   
(C++ , 1)  
e. 派发(shuffle)：将key相同的扔到一起去，即：  
(Hello , 1)  
(Hello , 1)  
(Hello , 1)  
(Hello , 1)   
(Java , 1)  
(Java , 1)  
(C , 1)  
(C++ , 1)  
f. 这一步需要移动数据，原来的数据可能在不同的datanode上，这一步过后，相同key的数据会被移动到同一台机器上。最终，它会返回一个list包含各种k-value对，即：  
{ Hello: 1,1,1,1}  
{Java: 1,1}  
{C: 1}  
{C++: 1}  
g. 缩减(reduce)：把同一个key的结果加在一起。如：  
(Hello , 4)   
(Java , 2)  
(C , 1)   
(C++,1)  
h. 输出(output): 输出缩减之后的所有结果。  
