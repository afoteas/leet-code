/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* ret = head->next;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* cur = second->next;
        first->next = cur;
        second->next = first;
        while(cur && cur->next) {
            ListNode* tmp = first;
            first = cur;
            second = cur->next;
            first->next = second->next;
            second->next = first;
            tmp->next = second;
            cur=first->next;
        }
        return ret;
    }

    ListNode* swapPairsRec(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        
        return newHead;
    }
};