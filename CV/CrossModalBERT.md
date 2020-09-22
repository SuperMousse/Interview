1. BERT 细节考点
a. BERT双向体现在什么地方？  
计算attention的时候, 当前词能够看到左右两侧的词, 只把当前词的系数通过Mask设为-inf, 然后softmax后为0， GPT只能看到左侧的词  
b. BERT如何预训练？   
Mask语言模型， 当前词换为mask，然后对其进行分类预测； 下一句预测： 选择句子A和句子B, 50%B真的在A后面，50%不是，通过[CLS]标记进行分类预测    
c. 对于MLM任务, 给定的句子中随机选择 15% 的标记，其中80%被换位[mask]，10%不变、10%随机替换其他单词，原因是什么？  
BERT在训练的时候有[mask], 但是在finetune的时候没有[mask], 当前词时可见的并且参与到最终向量的生成, 这导致了训练和使用的时候的bias,  其中一部分的词的随机替换相当于一方面进行“加噪”, 告诉模型输入的词有可能是错得, 另一方面在训练和finetune之间的bias进行平衡; 缺点是每次只有15的数据被标记, 需要更长时间来收敛； encoder 的输出上添加一个分类层,用嵌入矩阵乘以输出向量，将其转换为词汇的维度,用 softmax 计算mask中每个单词的概率  
d. NSP(Next Sentence Prediction):用一个简单的分类层将 [CLS] 标记的输出变换为 2×1 形状的向量,用 softmax 计算  
e. BERT是如何使用Transformer的？  
使用了Transformer的Encoder, 12层或24层  
f. BERT tokenizer: 
BERT将句子分解成：整个单词(如word), 出现在单词前面或者单独出现的子单词(em), 不在单词前面的子单词(##ing); tokenizer首先检查单词是否在词表中, 然后尝试分解为尽可能大的子单词, 最后分解为单个
字符, 并没有分解成[UNK]这种未登录字符
g. 词向量&句向量  
词向量/句向量: 最后2/4隐层求平均  
h. 词表外的词可以直接通过tokenizer分解之后求向量平均的方法来生成词向量  
i. BERT本身并不太适用于单词级别的相似度, 因为BERT本身是上下文相关的, 'river bank'河岸完全不同于'bank'银行  
j. BERT做多标签分类, 直接把单句输入BERT中, 然后在[CLS]标记上进行分类
k. NSP任务的缺点, NSP任务是50%直接从训练集中选取连续的两段话, 50%从不同的文件中选取一句话, 但是某些研究表明去除NSP反而在一些任务上取得了更好地结果, ALBERT作者认为这是由于NSP的任务难度
不够, 因为A、B来自不同的文件, 不需要进行句子语义级别的分类, 仅仅需要不同文本的分类学习就可以使得NSP学的很好; ALBERT中提出SOP(Self-supervised loss for sentence-order prediction), 只是把A、B句子对调, 在进行NSP学习, 强迫模型专注在下一句是否连续的预测上, 能够让模型学习到更多句子间的语义关系   
l. 为什么self-attention要除以sqrt(d), 除以的数字为什么是sqrt(d)  
当QK^T中向量维度增长时, 会导致内积的结果大幅度增加, 导致进入了softmax的梯度饱和区; 假设Q, K的每一个维度都是均值为0, 方差为1的独立随机变量, 那么QK^T=sum(q_i * k_i)的均值为0, 方差为d, 除以sqrt(d)之后让方差保持为1   



2. Video BERT  
a. 文本token follow BERT, 视觉token对frame level图像做hierarchical k-means做聚类，一共得到20736个类中心。把类中心作为visual token，每一个视觉特征向量都由它属于的类中心来表征  
b. mask语言模型 + 文本视觉对齐(判断是否来自同一个clip)

3. VL-BERT  
a. Language token + Faster R-CNN提取的视觉token做多任务学习， token embedding: 语言token + [IMG], Visual feature embedding: 全图(语言部分) + ROI(视觉部分); Segement Embedding: A, B; Position Embdding: 1, 2,.., 7;  
b. Mask语言模型  
c. Mask ROI分类, 随机mask一部分ROI, 置0, 注意全图上的对应位置也要置0  
d. VL-BERT用于多标签分类, 可以首先进行跨模态的pretrain, 遵照原有的自监督训练模式, 然后作为之后分类模型的初始化, 把caption和文本共同送入模型中, 在[CLS]标记上进行多标签分类,
端上场景分类和服务器上的内容审核  
e. VL-BERT用于跨模态检索, 预训练的时候把caption和文本共同送入模型中, 自监督训练,  然后抽取跨模态特征, 测试的时候输入query  


4. Fasion-BERT  
跨模态BERT的基础上提出了时尚领域的BERT, 直接Patch切分+多任务自适应损失  
a. 多任务模型: Mask语言模型; Mask视觉模型， 随机mask10%, 计算其真实值与计算值之间的KL散度; 视觉-文本对齐, 二分类；   
b. 多任务自适应损失： L = w_i * l_i, w_i = (L - grad(l_i)^2)^{-1} / normalize_sum, L = 3为任务数量  
c. 29w图片/描述对, 其中26w训练, 3w测试
d. 跨模态匹配: [CLS]标记输出的表示匹配得分
e. 跨模态检索: 两阶段, 预训练使用1000w<title, image> pair来进行训练, finetune使用200w<query, title, image> triplets, 使用query和点击的数据来构成fintune数据集, test时把新的query送入fasionBERT, 然后和已经抽取好的跨模态向量计算相似度  
f. 负样本构建?  

5. ViL-BERT  
a. 跨模态双流Transformer:  双流Transformer, 每一路的Q来自自己, K, V来自另外一个模态  
b. Mask语言模型+视觉文本对齐分类   
