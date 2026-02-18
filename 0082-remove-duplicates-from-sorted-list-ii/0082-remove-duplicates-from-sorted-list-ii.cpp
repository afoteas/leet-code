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
        if(!head) return nullptr;
        ListNode* ans = nullptr;
        ListNode* last = nullptr;
        bool can_add = true;
        int last_val = head->val;
        while(head) {
            ListNode* cur = head;
            head = head->next;
            if(head) {
                if(can_add) can_add = (last_val != head->val);
            }
            else {
                if(can_add) {
                    if(ans) last->next = cur;
                    else ans = cur;
                }
                break;
            }
            if (can_add) {
                if(!ans) {
                    ans = cur;
                    last = cur;
                    last->next = nullptr;
                } else {
                    last->next=cur;
                    last = last->next;
                    last->next = nullptr;
                }
            }
            can_add = (last_val != head->val);
            last_val = head->val;

        }
        return ans;
    }

    ListNode* deleteDuplicatesFirst(ListNode* head) {
        if(!head) return nullptr;
        unordered_map<int,int> seen;
        ListNode* ans = nullptr;
        ListNode* last = nullptr;
        seen[head->val]++;
        while(head) {
            ListNode* cur = head;
            head = head->next;
            if(head) {
                seen[head->val]++;
            }
            else {
                if(ans) {
                    if(seen[cur->val] == 1) last->next = cur;
                }
                else {
                    if(seen[cur->val] == 1) ans = cur;
                }
                break;
            }
            if(!ans) {
                if (seen[cur->val]==1) {
                    ans = cur;
                    last = cur;
                    last->next = nullptr;
                }
            } else {
                if (seen[cur->val]==1) {
                    last->next=cur;
                    last = last->next;
                    last->next = nullptr;
                } 
            }

        }
        return ans;
    }
};