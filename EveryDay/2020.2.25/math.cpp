// 1. 判断任意一个数字n是否是3的倍数

// 方法一: 各位数之和是否是3的倍数
// 方法二: 位运算: 计算二进制表达中奇数位为1和偶数位为1的差值, 差值能否被3整除
// 方法一: 求余数, 但无法适应大数
// 方法二: 一直做减法




// 对任意一个数字n高效乘7
// 位运算左移三位, 相当于*8, 变为8n, 然后减去n, 相当于*7
long multiplyBySeven(long n)  
{    
    /* Note the inner bracket here. This is needed   
       because precedence of '-' operator is higher   
       than '<<' */
    return ((n<<3) - n);  
}  
