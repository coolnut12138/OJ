链接：https://www.nowcoder.com/questionTerminal/f5805cc389394cf69d89b29c0430ff27?toCommentId=1538834
来源：牛客网

给定一个长度为N(N>1)的整型数组A，可以将A划分成左右两个部分，左部分A[0..K]，右部分A[K+1..N-1]，K可以取值的范围是[0,N-2]。求这么多划分方案中，左部分中的最大值减去右部分最大值的绝对值，最大是多少？

给定整数数组A和数组的大小n，请返回题目所求的答案。

测试样例：
[2,7,3,1,1],5
返回：6

//笨办法：从第一个位置开始分为左右两部分，分别求出两部分的最大值，然后相减算出差值，求出所有差值中最大的差值
class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
	// write code here
	int leftmax, rightmax;
	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			leftmax = *max_element(A.begin(), A.begin() + j);
			rightmax = *max_element(A.begin() + j, A.end());
		}
		max = abs(leftmax - rightmax) > max ? abs(leftmax - rightmax) : max;
	}
	return max;
}
};

//办法二：最小值只能在左右两端的其中一个
因为取的是两个分组中最大值之间的差值
比如{3，4，5，7，6}
第一个值是3，分组情况{3}{4，5，6，7}找后面最大值为7，差值为4
再比如{5，3，4，7，6}
	第一个值为5，分组情况{5}{3，4，7，6}或者{5，3}{4，7，6} 或者{5，3，4}{7，6}
	后面最大值为7，差值为2
	{5，3，4，7}{6}这样分是不行的，这样差值就变成1了，所以最小值就在两端，找出最小值
	，再找出数组中所有元素的最大值，进行相减得到差值。
class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        // write code here
        int min = A[0] > A[n - 1] ? A[n-1] : A[0];
        int max = A[0];
        for(int i = 0; i < n; i++){
            if(A[i] > max){
                max = A[i];
            }
        }
        return max - min;
    }
};