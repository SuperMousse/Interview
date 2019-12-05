 int climbStairs(int n) {
		 if (n > 0) {
			 if (n == 1) {
				 return 1;
			 }
			 if (n == 2) {
				 return 2;
			 }
			 int ahead = 1;
			 int behind = 2;
			 int res = 0;
			 for (int i = 3; i <= n; ++i) {
				 res = ahead + behind;
				 ahead = behind;
				 behind = res;
			 }
			 return res;
		 }
		 return -1;
	 }
