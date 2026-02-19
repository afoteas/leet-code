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