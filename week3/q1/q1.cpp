class Solution {
  public:
  // function to find the first node of a loop in linked list
    Node* findFirstNode(Node* head) {
        // slow to move 1 node each time
        Node* slow = head;
        // fast to move 2 nodes each time
        Node* fast = head;
        // till the fast doesn't reach the end
        while(fast != nullptr && fast->next != nullptr){
            // fast and slow moves
            slow = slow->next;
            fast = fast->next->next;                                                 // so let x be the distance before the loop
            // if fast and slow meets, that means there is a loop                    // let y be the distance moved till they meet in the loop
            if(slow==fast){                                                          // C be the lenght of the node
                // make slow as head                                                 // so when the distance is x+y, the spepration will also be x+y
                slow = head;                                                         // so x+y is a multiple of C
                // then make both slow and fast move 1 node each till they meet      // so that means, moving y by x more distance, we make the distance inside the loop a multiple of C
                while(slow != fast){                                                 // so basically we reach the start of the loop
                    slow = slow->next;                                               // and we dont have x, but we know if we keep movinf slow from the head to find x,
                    fast = fast->next;                                               // both slow and head will be at the start of the head
                }
                // when they meet, that will be the first node of the loop
                // return slow
                return slow;
            }
        }
        // if there is no loop, return nullptr
        return nullptr;
    }
};