题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）,
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr){
            return nullptr;
        }
        //1、复制链表,不复制random指针
        RandomListNode* cur = pHead;
        while(cur != nullptr){
            RandomListNode* copyNode = new RandomListNode(cur->label);
            RandomListNode* next = cur->next;
            cur->next = copyNode;
            copyNode->next = next;
            cur = next;
        }
        
        //2、复制random指针
        cur = pHead;
        while(cur != nullptr){
            if(cur->random == nullptr){
                cur->next->random = nullptr;
            }else{
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        //3、拆分链表
        cur = pHead;
        RandomListNode* newHead = pHead->next;
        while(cur != nullptr){
            RandomListNode* tmpNode = cur->next;
            cur->next = tmpNode->next;
            if(tmpNode->next == nullptr){
                tmpNode->next = nullptr;
            }else{
                tmpNode->next = tmpNode->next->next;
            }
            cur = cur->next;
        }
        return newHead;
    }
};