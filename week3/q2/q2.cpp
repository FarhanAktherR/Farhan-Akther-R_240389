class Solution {
public:
// function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        // if the head is nullptr, then return head(or else problem in next step when i access head->next)
        if(head == nullptr){
            return head;
        }
        // ptr to keep track of the node
        ListNode* ptr = head;
        // ptr_next to keep track of the next node
        ListNode* ptr_next = head->next;
        // make head->next as nullptr as this should be the last node in the reversed linked list
        head->next = nullptr;
        // while ptr_next doesn't reach the end
        while(ptr_next != nullptr){
            // temp node to store the next of ptr_next
            ListNode* temp = ptr_next->next;
            // link ptr_next to the previus nodw(ptr)
            ptr_next->next = ptr;
            // now move ptr 1 step forward(as ptr_next has the next node, make ptr as ptr_next)
            ptr = ptr_next;
            // now move ptr_next 1 step forward(make ptr_next as temp, which had the next node)
            ptr_next = temp;
        }
        // finally, ptr will have the head of the reversed linked list, so return that
        return ptr;
    }
};