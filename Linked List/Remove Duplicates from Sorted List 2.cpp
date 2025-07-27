class Solution {
public:
   ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head) {
            // If current node has duplicates
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // Remove them from the list
                prev->next = head->next;
            } else {
                // No duplicates; move prev
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};
