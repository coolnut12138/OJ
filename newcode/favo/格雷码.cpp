在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同， 则称这种编码为格雷码(Gray Code)，
请编写一个函数，使用递归的方法生成N位的格雷码。

给定一个整数n，请返回n位的格雷码，顺序为从0开始。

测试样例：
1
返回：["0","1"]

vector<string> getGray(int n) {
		// write code here
		// n位格雷码其实是在n-1位格雷码的基础上添加0、1得到的，添加规律为 n-1位格雷码正序前面添加0 逆序格雷码
		// 前面添加1 即可得到n位的格雷码 
		// 比如 1 位格雷码为 0 1，则2位为 00 01 11 10 三位为 000 001 011 010 110 111 101 100
		vector<string> result;
		if(n == 0)
		{
			return result;
		}
		else if(n == 1)
		{
			result.push_back("0");
			result.push_back("1");
			return result;
		}
			
		vector<string> temp = getGray(n-1);
		//正向添 0
		for(int i = 0; i < temp.size(); i++)
		{
			result.push_back("0" + temp[i]);
		}
		//反向添 1
		for(int i = temp.size() - 1; i >= 0; i--)
		{
			result.push_back("1" + temp[i]);
		}
		return result;
}