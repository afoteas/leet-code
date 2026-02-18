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