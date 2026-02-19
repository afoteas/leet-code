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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow=nullptr;
        ListNode* fast=head;
        bool inc = false;
        while(fast) {
            if(inc) {
                if(slow) slow=slow->next;
                else slow = head;
            }
            inc^=true;
            fast=fast->next;
        }
        slow->next = slow->next->next;
        return head;
        
    }

    ListNode* deleteMiddleSlo(ListNode* head) {
        if(!head) return nullptr;
        vector<ListNode*> l;
        while(head) {
            l.push_back(head);
            head=head->next;
        }
        if(l.size() == 1) return nullptr;
        int m = l.size() / 2;
        l[m-1]->next=l[m]->next;
        return l[0];
        
    }
};