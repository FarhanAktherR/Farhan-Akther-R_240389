// function to find the node where two linked list intersect
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // ptr1 to traverse over the first linked list
    ListNode* ptr1 = A;
    // ptr2 to traverse over the second linked list
    ListNode* ptr2 = B;
    // n1 and n2 to store the length of the first and second linked list respectively
    int n1 = 0, n2 = 0;
    // till ptr1 doesn't reach the end
    while(ptr1 != nullptr){
        // increment n1
        n1++;
        // move ptr1 to next node
        ptr1 = ptr1-> next;
    }
    // same as above for ptr2
    while(ptr2 != nullptr){
        n2++;
        ptr2 = ptr2-> next;
    }
    // now reset ptr1 and ptr2 to their respective heads
    ptr1 = A;
    ptr2 = B;
    // n to store the difference in length
    int n = n1 - n2;
    // now if 1st linked list is longer than the 2nd one
    if(n > 0){
        // move the ptr1 forward till the lenght ahead of it same as the length ahead of ptr2
        while(n > 0){
            ptr1 = ptr1->next;
            n--;
        }
    }
    // now if 2nd one is longer than the 1st
    else if(n < 0){
        // move the ptr2 forward till the lenght ahead of it same as the length ahead of ptr1
        while(n < 0){
            ptr2 = ptr2->next;
            n++;
        }
    }
    // the above step made sure that the length ahead of both ptr1 and ptr2 are same
    // this is becous we know that after they intersect, the number of nodes after that will be same
    // till ptr = ptr2
    while(ptr1 != ptr2){
        // keep moving both ptr1 and ptr2 forward
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // return the ptr1
    // which will be the intersecting node, if there is any intersection
    // else it will be nullptr as both ptr1 and ptr2 becomes nullptr when the reach the end
    return ptr1;
}