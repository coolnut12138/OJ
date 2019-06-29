leetcode �ڶ��⡣�������
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(-1);
		ListNode* cur = head;   //�������ƶ�
		int sum = 0;    //������λ��Ӻͽ�λ��ֵ
		bool carry = false;     //��λ��־

		while (l1 || l2){
			sum = 0;
			if (l1){
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2){
				sum += l2->val;
				l2 = l2->next;
			}
			if (carry){
				sum += 1;
			}

			ListNode *node = new ListNode(sum % 10);
			cur->next = node;
			cur = cur->next;
			if (sum >= 10){
				carry = true;
			}
			else{
				carry = false;
			}
		}
		if (carry){
			cur->next = new ListNode(1);
		}
		return head->next;
	}
};