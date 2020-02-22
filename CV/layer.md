1. linear

2. rnn

3. lstm

4. cnn

    class Conv2D(Layer):
        """A 2D Convolution Layer.
        Parameters:
        -----------
        n_filters: int
            The number of filters that will convolve over the input matrix. The number of channels
            of the output shape.
        filter_shape: tuple
            A tuple (filter_height, filter_width).
        input_shape: tuple
            The shape of the expected input of the layer. (batch_size, channels, height, width)
            Only needs to be specified for first layer in the network.
        padding: string
            Either 'same' or 'valid'. 'same' results in padding being added so that the output height and width
            matches the input height and width. For 'valid' no padding is added.
        stride: int
            The stride length of the filters during the convolution over the input.
        """
        def __init__(self, n_filters, filter_shape, input_shape=None, padding='same', stride=1):
            self.n_filters = n_filters
            self.filter_shape = filter_shape
            self.padding = padding
            self.stride = stride
            self.input_shape = input_shape
            self.trainable = True

        def initialize(self, optimizer):
            # Initialize the weights
            filter_height, filter_width = self.filter_shape
            channels = self.input_shape[0]
            limit = 1 / math.sqrt(np.prod(self.filter_shape))
            self.W  = np.random.uniform(-limit, limit, size=(self.n_filters, channels, filter_height, filter_width))
            self.w0 = np.zeros((self.n_filters, 1))
            # Weight optimizers
            self.W_opt  = copy.copy(optimizer)
            self.w0_opt = copy.copy(optimizer)

        def forward_pass(self, X, training=True):
            batch_size, channels, height, width = X.shape
            self.layer_input = X
            # Turn image shape into column shape
            # (enables dot product between input and weights)
            self.X_col = image_to_column(X, self.filter_shape, stride=self.stride, output_shape=self.padding)
            # Turn weights into column shape
            self.W_col = self.W.reshape((self.n_filters, -1))
            # Calculate output
            output = self.W_col.dot(self.X_col) + self.w0
            # Reshape into (n_filters, out_height, out_width, batch_size)
            output = output.reshape(self.output_shape() + (batch_size, ))
            # Redistribute axises so that batch size comes first
            return output.transpose(3,0,1,2)

    def image_to_column(images, filter_shape, stride, output_shape='same'):
        filter_height, filter_width = filter_shape

        pad_h, pad_w = determine_padding(filter_shape, output_shape)

        # Add padding to the image
        images_padded = np.pad(images, ((0, 0), (0, 0), pad_h, pad_w), mode='constant')

        # Calculate the indices where the dot products are to be applied between weights
        # and the image
        k, i, j = get_im2col_indices(images.shape, filter_shape, (pad_h, pad_w), stride)

        # Get content from image at those indices
        cols = images_padded[:, k, i, j]
        channels = images.shape[1]
        # Reshape content into column shape
        cols = cols.transpose(1, 2, 0).reshape(filter_height * filter_width * channels, -1)
        return cols

5. batchnorm/layernorm/instance norm/group norm
