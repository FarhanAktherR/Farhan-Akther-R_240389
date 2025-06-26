// recursive function to construct binary tree from inorder and postorder traversal
TreeNode* create(vector<int> &A, int i_A, int j_A, vector<int> &B, int i_B, int j_B, map<int,int> &m){
    // if the active region is empty, return nullptr
    if(i_A>j_A || i_B>j_B){
        return nullptr;
    }
    // x is the last value from the postorder, which will be the root
    int x = B[j_B];
    // create a a new node with x and make it root
    TreeNode* root = new TreeNode(x);
    // index stores the position of x in inorder vector
    int index = m[x];
    // n is the number of elements before index
    int n = index - i_A;
    // now to the left of the root
    // shrink the active region of inorder to elements before x
    // shrink the active region of postorder to the leftmost and same number of elements as active region of inorder
    root->left = create(A,i_A,index-1,B,i_B,i_B+n-1,m);
    // now to the right of the root
    // shrink the active region of inorder to elements after x
    // shrink the active region of postorder to the rightmost(except the root) and same number of elements as active region of inorder
    root->right = create(A,index+1,j_A,B,i_B+n,j_B-1,m);
    // return the root
    return root;
}
// function that returns the binary tree 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    // map to find the position of each value from the inorder vector
    map<int,int> m;
    // add the elements from the inorder vector to the map with their position
    for(int i=0;i<A.size();i++){
        m[A[i]] = i;
    }
    // return the binary tree
    return create(A,0,A.size()-1,B,0,B.size()-1,m);
}