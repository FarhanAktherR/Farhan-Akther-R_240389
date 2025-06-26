// function for inorder traversal without recursion
vector<int> Solution::inorderTraversal(TreeNode* A) {
    // vector to store inorder traversal values
    vector<int> bt;
    // stack to store the nodes
    stack<TreeNode*> s;
    // root for traversal, set first to A
    TreeNode* root = A;
    // till both root is null and s is empty
    while(root || !s.empty()){
        // while root is not null
        while(root){
            // add root to s
            s.push(root);
            // move to the left of root
            root = root->left;
        }
        // the above gets all the left nodes
        // now we start acessing from the last node added
        // now stores the last node added
        TreeNode* now = s.top();
        // remove the last node in s
        s.pop();
        // now add its value to bt
        bt.push_back(now->val);
        // root is set to its right to check the right branch
        root = now->right;
    }
    // return the vector
    return bt;
}