1. BERT 细节考点
a. BERT双向体现在什么地方？  
计算attention的时候, 当前词能够看到左右两侧的词, 只把当前词的系数通过Mask设为-inf, 然后softmax后为0， GPT只能看到左侧的词  
b. BERT如何预训练？   
Mask语言模型， 当前词换为mask，然后对其进行分类预测； 下一句预测： 选择句子A和句子B, 50%B真的在A后面，50%不是，通过[CLS]标记进行分类预测    
c. 对于MLM任务, 给定的句子中随机选择 15% 的标记，其中80%被换位[mask]，10%不变、10%随机替换其他单词，原因是什么？  
BERT在训练的时候有[mask], 但是在finetune的时候没有[mask], 当前词时可见的并且参与到最终向量的生成, 这导致了训练和使用的时候的bias,  其中一部分的词的随机替换相当于一方面进行“加噪”, 告诉模型输入的词有可能是错得, 另一方面在训练和finetune之间的bias进行平衡; 缺点是每次只有15的数据被标记, 需要更长时间来收敛；      
d. BERT是如何使用Transformer的？  
使用了Transformer的Encoder, 12层或24层  
e. BERT tokenizer: 
BERT将句子分解成：整个单词(如word), 出现在单词前面或者单独出现的子单词(em), 不在单词前面的子单词(##ing); tokenizer首先检查单词是否在词表中, 然后尝试分解为尽可能大的子单词, 最后分解为单个
字符, 并没有分解成[UNK]这种未登录字符
f. 词向量&句向量  
词向量/句向量: 最后2/4隐层求平均  
g. 词表外的词可以直接通过tokenizer分解之后求向量平均的方法来生成词向量  
h. BERT本身并不太适用于单词级别的相似度, 因为BERT本身是上下文相关的, 'river bank'河岸完全不同于'bank'银行  
i. BERT做多标签分类, 直接把单句输入BERT中, 然后在[CLS]标记上进行分类

2. Video BERT  
a. 文本token follow BERT, 视觉token对frame level图像做hierarchical k-means做聚类，一共得到20736个类中心。把类中心作为visual token，每一个视觉特征向量都由它属于的类中心来表征  
b. mask语言模型 + 文本视觉对齐(判断是否来自同一个clip)

3. VL-BERT  
a. Language token + Faster R-CNN提取的视觉token做多任务学习， token embedding: 语言token + [IMG], Visual feature embedding: 全图(语言部分) + ROI(视觉部分); Segement Embedding: A, B; Position Embdding: 1, 2,.., 7;  
b. Mask语言模型  
c. Mask ROI分类, 随机mask一部分ROI, 置0, 注意全图上的对应位置也要置0  



4. Fasion-BERT  
跨模态BERT的基础上提出了时尚领域的BERT, 直接Patch切分+多任务自适应损失  
a. 多任务模型: Mask语言模型; Mask视觉模型， 随机mask10%, 计算其真实值与计算值之间的KL散度; 视觉-文本对齐, 二分类；   
b. 多任务自适应损失： L = w_i * l_i, w_i = (L - grad(l_i)^2)^{-1} / normalize_sum, L = 3为任务数量  
c. 29w图片/描述对, 其中26w训练, 3w测试
d. 跨模态匹配: [CLS]标记输出的表示匹配得分, 

5. ViL-BERT  
a. 跨模态双流Transformer:  双流Transformer, 每一路的Q来自自己, K, V来自另外一个模态  
b. Mask语言模型+视觉文本对齐分类   
