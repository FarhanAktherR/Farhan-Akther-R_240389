// recursive function to reverse a linked list
ListNode* Solution::reverseList(ListNode* A) {
    // if A or the next node of A is nullptr
    if(A == nullptr || A->next == nullptr){
        // return A
        return A;
    }
    // new_head to store the head of the reversed linked list
    // so this process goes till it reaches the end (the termination condition above)
    // then it will be the last node and it will get caried by the return statment in the end to the first function call
    // and the last nod of the actual linked list will be head of the reversed linkd list
    ListNode* new_head = reverseList(A->next);
    // now the below process is going to start from the last(when the above function call gets return value)
    // reverse the link
    A->next->next = A;
    // now make the next of the node as nullptr
    A->next = nullptr;
    // return the head of the reversed linked list
    return new_head;
}