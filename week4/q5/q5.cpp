// function to find the node with value just greater than B
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // to store the node, set as null incase no such node
    TreeNode* x = NULL;
    // till A doesn't reach null
    while(A){
        // if the value is greater than B, resubstitute x as A
        // then move A to left, to find if there is even smaller possible value of x
        if(A->val > B){
            x = A;
            A = A->left;
        }
        // if the value of A is less than or equal to B
        // move to right to try to make it greater than B
        else{
            A = A->right;
        }
    }
    // return the node
    return x;
}