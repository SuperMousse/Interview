1. BERT 细节考点
a. BERT双向体现在什么地方？  
计算attention的时候, 当前词能够看到左右两侧的词, 只把当前词的系数通过Mask设为-inf, 然后softmax后为0， GPT只能看到左侧的词  
b. BERT如何预训练？   
Mask语言模型， 当前词换为mask，然后对其进行分类预测； 下一句预测： 选择句子A和句子B, 50%B真的在A后面，50%不是，通过[CLS]标记进行分类预测    
c. 对于MLM任务, 给定的句子中随机选择 15% 的标记，其中80%被换位[mask]，10%不变、10%随机替换其他单词，原因是什么？  
BERT在训练的时候有[mask], 但是在finetune的时候没有[mask], 当前词时可见的并且参与到最终向量的生成, 这导致了训练和使用的时候的bias,  其中一部分的词的随机替换相当于一方面进行“加噪”, 告诉模型输入的词有可能是错得, 另一方面在训练和finetune之间的bias进行平衡; 缺点是每次只有15的数据被标记, 需要更长时间来收敛；      
d. BERT是如何使用Transformer的？  
使用了Transformer的Encoder, 12层或24层  


2. Video BERT  


3. VL-BERT  



4. Fasion-BERT  
