//�����㷨���������
//ת���ַ�����ǰ��Ƚ�
bool isPalindrome(int x) {
	//ת���ַ�����ǰ��Ƚ�
	string s = to_string(x);
	for (size_t i = 0; i < s.size() / 2; i++){
		if (s[i] != s[s.size() - 1 - i]){
			return false;
		}
	}
	return true;
}

//��ת�ַ������Ƚ�
bool isPalindrome(int x) {
	string s1 = to_string(x);
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	if (s1 != s2)
		return false;
	return true;
}



//�����㷨���������
//����Ҫ�� x = 1234321 �Ƿ��ǻ�����
//��һ��������һ���������� help ���� help = 1000000������ x ��λ����ͬ
//�ڶ�����Ȼ�� x % 10 ȡ��ĩβλ�� x / help ȡ����λ�����бȽϣ������ͬ���ǻ�����
//�����������ǰ����λ��ͬ������ͷȥβ��x % help ȥ����λ��x / 10 ȥ��βλ��helpҲ��Ӧ������λ����������Ĳ���

bool isPalindrome(int x) {
	if (x < 0){
		return false;
	}
	int help = 1;   //����λ
	while (x / help >= 10){  //��ֹhelp���
		help *= 10;         //��help������x��ͬλ��������x = 123����ô��help��Ϊ100��
	}

	while (x != 0){
		if ((x % 10) != (x / help)){     //x%10��x�����һλ��x/help��x�ĵ�һλ��ǰ��Ƚ�
			return false;
		}

		x = (x % help) / 10;       //��x����ȥβ��x%helpȥ����λ��/10ȥ��βλ
		help /= 100;    //helpҲ������λ
	}
	return true;
}