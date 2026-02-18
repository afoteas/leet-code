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
            cout<<"last_val1:"<<last_val<<"can_add:"<<can_add<<endl;
            if(head) {
                if(can_add) {
                    // if(last_val != head->val) {
                    //     // last_val = head->val;
                    // } else {
                    //     cout<<"last_val:"<<last_val<<",head->val:"<<head->val<<endl;
                    //     can_add = false;
                    //     // last_val = head->val;
                    // }
                    can_add = (last_val != head->val);
                }
            }
            else {
                if(ans) {
                    if(can_add) last->next = cur;
                }
                else {
                    if(can_add) ans = cur;
                }
                break;
            }
            if(!ans) {
                if (can_add) {
                    ans = cur;
                    last = cur;
                    last->next = nullptr;
                }
            } else {
                if (can_add) {
                    last->next=cur;
                    last = last->next;
                    last->next = nullptr;
                } 
            }
            if(last_val != head->val) {
                cout<<"if:last_val:"<<last_val<<endl;
                cout<<"can_add:"<<can_add<<endl;
                can_add = true;
            } else {
                cout<<"else:last_val:"<<last_val<<endl;
                cout<<"head->val:"<<head->val<<endl;
                can_add = false;
            }
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