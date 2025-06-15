// function to remove duplicates from a sorted linked list
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // ptr to traverse the linked list
    ListNode* ptr = A;
    // till ptr or ptr->next doesn't reach the end
    while(ptr != nullptr && ptr->next != nullptr){
        // if ptr and ptr->next are equal
        if(ptr->val == ptr->next->val){
            // store ptr->next in a temp node
            ListNode* temp = ptr->next;
            // make ptr as the next of ptr->next (basically skip ptr->next)
            ptr->next = ptr->next->next;
            // now delete ptr->next, that we stored in temp
            delete temp;
        }
        else{
            // if not equal, then move ptr 1 node forward
            ptr = ptr->next;
        }
    }
    // finally return the head of the linked list with the duplicates removed
    // which is A, as we made changes to the linked list itslef
    return A;
}