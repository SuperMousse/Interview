// 判断任意一个数是否是11的倍数
// 方法一: 求余
// 方法二" 将奇数位的和与偶数位的和做差, 判断结果能否被11整除
// 任意四位数ABCD = 1000A + 100B + 10C + D
//              = 1001A - A + 99B + B + 11C - C + D
                = (1001A + 99B + 11C) + (- A + B - C + D)
// 转换成判断(- A + B - C + D)能否被11整除
// 因为10的偶数幂 - 1(99, 9999)都能被11整除, 10的奇数幂 + 1(11, 1001)都能被11整除


// 1. 判断任意一个数字n是否是3的倍数

// 方法一: 各位数之和是否是3的倍数
// 方法二: 求余数, 但无法适应大数
// 方法三: 一直做减法
// 方法四: 位运算: 计算二进制表达中奇数位为1和偶数位为1的差值, 差值能否被3整除
// 如二进制: ABCD = A*2^3 + B*2^2 + C*2^1 + D
//              = A*9 - 1 + B*3 + 1 + C*3 - 1 + D  (如果对应位置上为1才进行加减操作)
                 = -1 + 1 - 1 + D
// 所以奇数位上的数字记为+1, 偶数位记-1, 求和看能否被3整除
// 因为2^奇数次幂 + 1能被3整除, 2^偶数次幂 - 1能被3整除

int isMultipleOf3(int n) 
{ 
    int odd_count = 0; 
    int even_count = 0; 
  
    /* Make no positive if +n is multiple of 3 then is -n. We are doing this to avoid 
    stack overflow in recursion*/
    if (n < 0) 
        n = -n; 
    if (n == 0) 
        return 1; 
    if (n == 1) 
        return 0; 
  
    while (n) { 
        /* If odd bit is set then 
        increment odd counter */
        if (n & 1) 
            odd_count++; 
  
        /* If even bit is set then 
        increment even counter */
        if (n & 2) 
            even_count++; 
        n = n >> 2; 
    } 
  
    return isMultipleOf3(abs(odd_count - even_count)); 
} 


// 对任意一个数字n高效乘7
// 位运算左移三位, 相当于*8, 变为8n, 然后减去n, 相当于*7
long multiplyBySeven(long n)  
{    
    /* Note the inner bracket here. This is needed   
       because precedence of '-' operator is higher   
       than '<<' */
    return ((n<<3) - n);  
}  
