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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto gcd = [](int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b; // Remainder becomes the new b
                a = temp;  // Old b becomes the new a
            }
            return a;
        };

        ListNode* temp = head;
        while (temp->next) {
            temp->next = new ListNode(gcd(temp->val, temp->next->val), temp->next);
            temp = temp->next->next;
        }
        return head;
    }
};