#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	};
};

/*请完成下面这个函数，实现题目要求的功能
******************************开始写代码******************************/
ListNode* partition(ListNode* head, int m) {
	ListNode* dummy1 = new ListNode(-1);
	ListNode* dummy2 = new ListNode(-1);
	ListNode* p1 = dummy1;
	ListNode* p2 = dummy2;
	ListNode* p = head;
	while (p != nullptr) {
		if (p->val <= m) {
			p1->next = p;
			p1 = p1->next;
		}
		else {
			p2->next = p;
			p2 = p2->next;
		}
		p = p->next;
	}
	p2->next = nullptr;
	p1->next = dummy2->next;
	return dummy1->next;
}
/******************************结束写代码******************************/


int main() {
	ListNode* head = NULL;
	ListNode* node = NULL;
	int m;
	cin >> m;
	int v;
	while (cin >> v) {
		if (head == NULL) {
			node = new ListNode(v);
			head = node;
		}
		else {
			node->next = new ListNode(v);
			node = node->next;
		}
	}
	head = partition(head, m);
	if (head != NULL) {
		cout << head->val;
		node = head->next;
		delete head;
		head = node;
		while (head != NULL) {
			cout << "," << head->val;
			node = head->next;
			delete head;
			head = node;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
