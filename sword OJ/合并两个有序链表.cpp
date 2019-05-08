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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr){
			return pHead2;
		}
		if (pHead2 == nullptr){
			return pHead1;
		}
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		ListNode* newHead = nullptr;
		ListNode* newTail = nullptr;
		while (cur1 && cur2){
			if (cur1->val <= cur2->val){
				if (newTail == nullptr){
					newHead = newTail = cur1;
				}
				else{
					newTail->next = cur1;
					newTail = newTail->next;
				}
				cur1 = cur1->next;
			}
			else{
				if (newTail == nullptr){
					newHead = newTail = nullptr;
				}
				else{
					newTail->next = cur2;
					newTail = newTail->next;
				}
				cur2 = cur2->next;
			}
		}
		if (cur1){
			newTail->next = cur1;
		}
		if (cur2){
			newTail->next = cur2;
		}
		return newHead;
	}
};