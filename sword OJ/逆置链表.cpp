/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* p0 = nullptr;
		ListNode* p1 = pHead;
		ListNode* p2 = pHead->next;
		while (p1 != nullptr){
			p1->next = p0;
			p0 = p1;
			p1 = p2;
			if (p2 != nullptr){
				p2 = p2->next;
			}
		}
		return p0;
	}
};