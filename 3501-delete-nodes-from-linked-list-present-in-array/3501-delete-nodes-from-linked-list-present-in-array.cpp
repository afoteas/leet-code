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
 #include <unordered_set>
 using namespace std;

    //  def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
    //     n = set(nums)
    //     dummy = ListNode(0)
    //     dummy.next = head
    //     curr = dummy
    //     while curr.next:
    //         if (curr.next.val in n):
    //             curr.next = curr.next.next
    //         else:
    //             curr = curr.next
    //     return dummy.next
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> const  n(begin(nums), end(nums));
        ListNode dummy(0, head);
        ListNode* curr = &dummy;

        while (curr->next) {
            if (n.count(curr->next->val)) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return dummy.next; 
    }
};