//ţ�ͣ�ջ�ĵ���ѹ������
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> ret;
		//��������������������vector
		int pushIdx = 0;
		int popIdx = 0;
		int size = pushV.size();
		//1�������Ԫ��ѹջ
		while (pushIdx < size){
			ret.push(pushV[pushIdx++]);
			//2��ѹһ�αȽ�ջ��Ԫ���Ƿ����ջ���еĵ�һ��Ԫ�����
			//����ȣ���ջ��Ԫ�س�ջ����������������ջ����ѹջ��ѭ��1��2��
			while (!ret.empty() && ret.top() == popV[popIdx]){
				ret.pop();
				++popIdx;
			}
		}
		//������ջΪ�գ���Ԫ��ȫ���ȶ���ϣ���ó�ջ��������ȷ��һ��
		return ret.empty();
	}
};