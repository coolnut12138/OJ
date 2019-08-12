反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* p0 = nullptr;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p1 != nullptr){
            p1->next = p0;
            p0 = p1;
            p1 = p2;
            if(p2 != nullptr){
                p2 = p2->next;
            }
        }
        return p0;
    }
};