//leetcode225.用队列实现栈
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		//一个队列，出队只出size - 1个元素，剩下的就是实现栈的栈顶元素，将出队的元素再入队
		int count = q.size() - 1;
		while (count > 0){
			int num = q.front();
			q.pop();
			q.push(num);
			--count;
		}
		int ret = q.front();
		q.pop();
		return ret;
	}

	/** Get the top element. */
	int top() {
		return q.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
private:
	queue<int> q;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/