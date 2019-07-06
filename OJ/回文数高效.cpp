//菜鸟算法：求回文数
//转成字符串，前后比较
bool isPalindrome(int x) {
	//转成字符串。前后比较
	string s = to_string(x);
	for (size_t i = 0; i < s.size() / 2; i++){
		if (s[i] != s[s.size() - 1 - i]){
			return false;
		}
	}
	return true;
}

//反转字符串，比较
bool isPalindrome(int x) {
	string s1 = to_string(x);
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	if (s1 != s2)
		return false;
	return true;
}



//左神算法：求回文数
//比如要求 x = 1234321 是否是回文数
//第一步：定义一个辅助变量 help ；让 help = 1000000；即与 x 的位数相同
//第二步：然后 x % 10 取得末尾位， x / help 取得首位，进行比较，如果不同则不是回文数
//第三步：如果前后两位相同，则将掐头去尾，x % help 去除首位，x / 10 去除尾位。help也对应减少两位，继续上面的步骤

bool isPalindrome(int x) {
	if (x < 0){
		return false;
	}
	int help = 1;   //辅助位
	while (x / help >= 10){  //防止help溢出
		help *= 10;         //将help扩大到与x相同位数，比如x = 123，那么将help变为100；
	}

	while (x != 0){
		if ((x % 10) != (x / help)){     //x%10是x的最后一位，x/help是x的第一位，前后比较
			return false;
		}

		x = (x % help) / 10;       //将x掐首去尾，x%help去掉首位，/10去掉尾位
		help /= 100;    //help也减少两位
	}
	return true;
}