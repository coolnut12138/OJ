//ì³²¨ÄÇÆõÊýÁÐ
class Solution {
public:
	int Fibonacci(int n) {
		/*µÝ¹é
		if(n == 0){
		return 0;
		}

		if(n >= 1 && n <= 2){
		return 1;
		}
		else{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
		}*/
		//·ÇµÝ¹é
		if (n == 0){
			return 0;
		}
		int a = 1;
		int b = 1;
		int ret = 1;
		for (int i = 0; i < n - 2; i++){
			ret = a + b;
			a = b;
			b = ret;
		}
		return ret;
	}
};