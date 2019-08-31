题目描述
输入两个链表，找出它们的第一个公共结点。
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
    int Length(ListNode* head){
        int count = 0;
        while(head != nullptr){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = Length(pHead1);
        int len2 = Length(pHead2);
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        if(len1 > len2){
            for(int i = 0; i < len1 - len2; i++){
                cur1 = cur1->next;
            }
        }else if(len1 < len2){
            for(int i = 0; i < len2 - len1; i++){
                cur2 = cur2->next;
            }
        }
        
        while(cur1 != nullptr){
            if(cur1->val != cur2->val){
                cur1 = cur1->next;
                cur2 = cur2->next;
            }else{
                break;
            }
        }
        return cur1;
    }
};