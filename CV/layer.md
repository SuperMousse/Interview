1. linear

2. rnn

3. lstm

4. cnn
```
class Conv2d(object):
    def __init__(self, in_channel, out_channel, kernel_size, padding=0, stride=1):
        self.in_channel = in_channel
        self.out_channel = out_channel
        self.kernel_size = kernel_size
        self.kernel_height, self.kernel_width = kernel_size
        self.padding = padding
        self.stride = stride
        self.reset_params()
    
    def reset_params(self):
        self.W = np.random.rand(self.out_channel, self.in_channel, self.kernel_height, self.kernel_width)
        self.b = np.zeros((self.out_channel, 1))
        
    def forward(self, X):
        B, C, H, W = X.shape
        self.output_height = int(H + 2 * self.padding - self.kernel_height) // self.stride + 1
        self.output_width = int(W + 2 * self.padding - self.kernel_width) // self.stride + 1
        # Turn image shape into column shape
        # (enables dot product between input and weights)
        X_col = self.image_to_column(X, 
                                     self.kernel_size, 
                                     stride=self.stride, 
                                     padding=self.padding) # [h*w*in_channel, output_height*output_width*B]
        W_col = self.W.reshape((self.out_channel, -1)) # [out_channnel, in_channel*h*w]

        output = W_col.dot(X_col) + self.b # [out_channel, output_height*output_width*B] 
        output = output.reshape(self.out_channel, self.output_height, self.output_width, B)
        output = output.transpose(3, 0, 1, 2) 
        return output
    
    def image_to_column(self, images, kernel_size, stride, padding):
        images_padded = np.pad(images, ((0, 0), (0, 0), (padding, padding), (padding, padding)), mode='constant')
        # Calculate the indices where the dot products are to be applied between weights
        # and the image
        k, i, j = self.get_im2col_indices(images.shape, 
                                          kernel_size, 
                                          stride)
        # cols = [B, kernel_height*kernel_width*in_channel, outshape_height*outshape_width]
        cols = images_padded[:, k, i, j] 
        # Reshape content into column shape
        cols = cols.transpose(1, 2, 0).reshape(self.kernel_height * self.kernel_width * self.in_channel, -1)
        return cols
    
    def get_im2col_indices(self, images_shape, kernel_size, stride):
        kernel_height, kernel_width = kernel_size
        # i是单个channel[kernel_height, kernel_width]的行索引, 每个数字重复kernel_width次, 循环
        i0 = np.repeat(np.arange(kernel_height), kernel_width)
        # i是行索引, 拷贝channel次, 对应不同的输入channel
        i0 = np.tile(i0, self.in_channel)
        # i1为卷积核移动时的偏置, i0+偏置=所有移动位置上的索引
        # i1表示行号每移动output_width次才变更一次, 因此[0, 0, 1, 1, 2, 2]表示输出output_height*output_width大小
        # feature map的行标变化
        i1 = stride * np.repeat(np.arange(self.output_height), self.output_width)
        # j是[kernel_height, kernel_width]的列索引, 每个数字重复1次, 循环
        j0 = np.tile(np.arange(kernel_width), kernel_height * self.in_channel)
        # j1为偏置, 列表每移动output_height次才变更一次
        j1 = stride * np.tile(np.arange(self.output_width), self.output_height)
        i = i0.reshape(-1, 1) + i1.reshape(1, -1)
        j = j0.reshape(-1, 1) + j1.reshape(1, -1)
        # k是channel的索引, 每一个数字重复kernel_height * kernel_width次, 循环[0,0,...0, 1, 1, ...1]
        k = np.repeat(np.arange(self.in_channel), kernel_height * kernel_width).reshape(-1, 1)
    
```
5. batchnorm/layernorm/instance norm/group norm
