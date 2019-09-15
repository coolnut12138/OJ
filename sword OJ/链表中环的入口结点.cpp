/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntranceOfCycle(ListNode* head){
        //快指针一次走两步，慢指针一次走一步，最终会在环内某结点相遇
        ListNode* fast = head;
        ListNode* slow = head;
        do
        {
            if(fast == nullptr){
                break;
            }
            fast = fast->next;
            if(fast == nullptr){
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }while(slow != fast);
        return fast;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //从环内相遇结点开始一次走一步，从链表头开始一次走一步，最终会在链表环入口结点相遇
        ListNode* meet = EntranceOfCycle(pHead);
        if(meet == nullptr){
            return nullptr;
        }
        ListNode* node = pHead;
        while(meet != node){
            meet = meet->next;
            node = node->next;
        }
        return meet;
    }
};