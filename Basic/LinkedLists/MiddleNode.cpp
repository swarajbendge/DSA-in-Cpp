// There are two waye to find middle node of a Singly Linked List
// 1. Find the lenght and then lenght/2
// 2. Slow Fast Pointer


// 1.
// find the lenght and then length/2
int getLength(ListNode* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}
ListNode* middleNodeLength(ListNode* head) {
    int len = getLength(head);
    int mid = len / 2;
    ListNode* temp = head;
    for (int i = 0; i < mid; i++) {
        temp = temp->next;
    }
    return temp;
}


// 2.
// Function to find the middle node using slow-fast pointer method
ListNode* middleNodeSlowFast(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
