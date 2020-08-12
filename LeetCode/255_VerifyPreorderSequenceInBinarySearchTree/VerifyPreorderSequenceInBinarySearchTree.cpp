// 给定一个序列, 判断是否是二叉搜索树的前序遍历序列
// 例子
//     5
//    / \
//   2   6
//  / \
// 1   3

// Input: [5,2,6,1,3]
// Output: false
//
// Input: [5,2,1,3,6]
// Output: true

// 分析: 根节点数值 < 即将到来的右子树节点数值, 如果已知根节点, 可以用来决定即将到来的值是否有效
// 使用栈存储从根节点到左子树的数值, 当遇到了一个比栈顶数字更大的数时, 认为遇到了局部的一个右子节点,
// 把比这个节点小的数字都出栈, 也就是把他的左子节点和根节点出栈, 最后留下的lower是这个右子节点,
// 他对应了某个左子树上的最大节点, 后续遇到更大的数字的时候表示遇到了新的右子树, 把比它小的数字
// 都出栈, 那么此后的数值都不能比lower_bound小

bool verifyPreorder(vector<int>& preorder) {
    stack<int> st;
    int lower_bound= INT_MIN;
    for(auto n: preorder){
        if(n < lower_bound)
            return false;
        while(!st.empty() && n > st.top()){
            lower_bound= st.top();
            st.pop();
        }
        st.push(n);
    }
    return true;
}
