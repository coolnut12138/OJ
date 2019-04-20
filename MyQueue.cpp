
//leetcode ����ջʵ�ֶ���
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		//ѹջȫѹ��a��
		a.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		//��ջ�Ȱ�a������Ԫ�ط���b�У�Ȼ��bջ��Ԫ�ؾ��Ƕ���Ԫ��,Ȼ���Ƚ��ȳ����Ƕ�������
		if (b.empty()){
			while (!a.empty()){
				b.push(a.top());
				a.pop();
			}
		}
		int x = b.top();
		b.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		//�Ȱ�a������Ԫ�ط���b�У�Ȼ��bջ��Ԫ�ؾ��Ƕ���Ԫ��
		if (b.empty()){
			while (!a.empty()){
				b.push(a.top());
				a.pop();
			}
		}
		return b.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return a.empty() && b.empty();
	}

private:
	stack<int> a;
	stack<int> b;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/