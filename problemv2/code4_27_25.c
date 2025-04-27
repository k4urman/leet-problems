/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = createNode(0);
    struct ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->value;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->value;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
    }

    return dummyHead->next;
}
