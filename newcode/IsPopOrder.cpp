//牛客：栈的弹出压入序列
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> ret;
		//两个坐标用来遍历两个vector
		int pushIdx = 0;
		int popIdx = 0;
		int size = pushV.size();
		//1、将入队元素压栈
		while (pushIdx < size){
			ret.push(pushV[pushIdx++]);
			//2、压一次比较栈顶元素是否与出栈序列的第一个元素相等
			//若相等，将栈顶元素出栈，不相等则继续将入栈序列压栈，循环1、2、
			while (!ret.empty() && ret.top() == popV[popIdx]){
				ret.pop();
				++popIdx;
			}
		}
		//若最终栈为空，则元素全部比对完毕，则该出栈序列是正确的一个
		return ret.empty();
	}
};