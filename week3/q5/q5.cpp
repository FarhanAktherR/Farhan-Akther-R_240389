// function to reverse the nodes of a linked list at even position
ListNode* Solution::solve(ListNode* A) {
    // ptr to traverse on A, and set it as A->next as it is the first even position
    ListNode* ptr = A->next;
    // even to store the head of the reversed linked list with only even position
    ListNode* even = nullptr;
    // till ptr or ptr->next reaches end
    while(ptr != nullptr && ptr->next != nullptr){
        // create a new node temp with the value as ptr
        ListNode* temp = new ListNode(ptr->val);
        // make next of temp as even
        temp->next = even;
        // update even to temp
        even = temp;
        // now move ptr 2 nodes ahead for the next even position
        ptr = ptr->next->next;
    }
    // if the above loop stopped because of ptr->next = nullptr
    // then the last even node was not added to even
    // so if ptr was not nullptr, then do the same as above 1 more time
    if(ptr != nullptr){
        ListNode* temp = new ListNode(ptr->val);
        temp->next = even;
        even = temp;
    }
    // now reset the value of ptr to A
    ptr = A;
    // now we are going to merge both the linked lists
    // till either of even or ptr reaches the end
    while(even != nullptr && ptr != nullptr){
        // temp1 to store ptr->next(even position), that we will delete later
        ListNode* temp1 = ptr->next;
        // temp2 to store even->next
        ListNode* temp2 = even->next;
        // link ptr to even;
        ptr->next = even;
        // link even to the next odd node(that is temp1->next)
        even->next = temp1->next;
        // update ptr to the next even node
        ptr = temp1->next;
        // update even to the next node
        even = temp2;
        // delete the even position nod from the actual linked list
        delete temp1;
    }
    // return the head of the updated linked list, which will be A itself
    return A;
}