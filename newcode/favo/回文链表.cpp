请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    ListNode* getMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        if(fast == nullptr){
            return slow;
        }
        while(fast != nullptr){
            slow = slow->next;
            if(fast->next != nullptr){
                fast = fast->next->next;
            }else{
                break;
            }
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* node, ListNode* prev){
        if(node->next == nullptr){
            node->next = prev;
            return node;
        }
        ListNode* tmp = node->next;
        node->next = prev;
        prev = node;
        node = tmp;
        return reverseList(node, prev);
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr){
            return true;
        }
        ListNode* middle = getMiddle(head);
        ListNode* rever = reverseList(middle, nullptr);
        while(rever != nullptr){
            if(rever->val != head->val){
                return false;
            }
            rever = rever->next;
            head = head->next;
        }
        return true;
    }
};