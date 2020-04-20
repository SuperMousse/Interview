  // 注意a和b有可能是负数, 需要在carry中考虑符号
  int getSum(int a, int b) {
      if (a == 0) {
          return b;
      }
      if (b == 0) {
          return a;
      }
      int sum = 0;
      int carry = 0;
      while (b != 0) { // b = 0表示carrt = 0, 再无进位
          sum = a ^ b; // 保留所有不同位置
          carry = (unsigned)(a & b) << 1; // 所有相同且为1的位置都要进位, unsigned用来处理负数
          a = sum;
          b = carry;
      }
      return a;
  }
