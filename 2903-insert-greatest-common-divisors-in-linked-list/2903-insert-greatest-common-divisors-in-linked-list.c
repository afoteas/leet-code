/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// GCD function using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b; // Remainder becomes the new b
        a = temp;  // Old b becomes the new a
    }
    return a;
}

// Function to create a new ListNode
struct ListNode* createNode(int value, struct ListNode* next) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = next;
    return newNode;
}


struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* temp = head;
    while (temp->next) {
        temp->next = createNode(gcd(temp->val, temp->next->val), temp->next);
        temp = temp->next->next;
    }
    return head;
}
