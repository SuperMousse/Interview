// 1. 判断任意一个数字n是否是3的倍数

// 方法一: 求余数, 但无法适应大数
// 方法二: 一直做减法


// 方法二: 将m奇数位和偶数位相减, 判断得到的结果是否是n的倍数, 是的话就是n的倍数
// 对于任意一个数字ABCD
// 




// 对任意一个数字n高效乘7
// 位运算左移三位, 相当于*8, 变为8n, 然后减去n, 相当于*7
long multiplyBySeven(long n)  
{    
    /* Note the inner bracket here. This is needed   
       because precedence of '-' operator is higher   
       than '<<' */
    return ((n<<3) - n);  
}  
