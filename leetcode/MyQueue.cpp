
//leetcode 两个栈实现队列
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		//压栈全压进a中
		a.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		//出栈先把a中所有元素放入b中，然后b栈顶元素就是队首元素,然后先进先出就是队列特性
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
		//先把a中所有元素放入b中，然后b栈顶元素就是队首元素
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