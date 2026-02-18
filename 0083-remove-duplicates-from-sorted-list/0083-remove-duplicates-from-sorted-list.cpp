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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
            while(cur) {
                ListNode* tmp = cur;
                cur=cur->next;
                while(cur && tmp->val == cur->val) {
                    tmp->next=cur->next;
                    cur=cur->next;
                }
            }
        return head;
    }
};