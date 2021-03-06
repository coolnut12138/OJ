给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //快慢指针
        if(head == nullptr){
            return nullptr;
        }
        ListNode* p = head;
        while(n != 0 && p->next != nullptr){  //走完n，后面的慢指针就刚好走到要删除结点的前面
            p = p->next;
            n--;
        }
        if(n > 1) //表示链表长度小于n
            return head;
        if(n == 1)  //表示删除头结点
            return head->next;
        
        ListNode *p2 = head;
        while(p->next != nullptr){
            p = p->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};