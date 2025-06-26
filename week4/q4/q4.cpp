// recursive function to fund the path
bool addPath(TreeNode* root, int x, vector<int>& path) {
    // if root is null, return false
    if(!root){
        return false;
    }
    // if it is not null, then add its value to path
    path.push_back(root->val);
    // if the value is equal to the target, return true
    if (root->val == x){
        return true;
    }
    // if the left or right path contains the target, return true
    if (addPath(root->left, x, path) || addPath(root->right, x, path)){
        return true;
    }
    // if target not present in neither of the branch, remove the value from path and return false
    path.pop_back();
    return false;
}
// function to find the least common ancestor 
int Solution::lca(TreeNode* A, int B, int C) {
    // vector to store the path to reach B
    vector<int> v_b;
    // function to fund the path to B
    addPath(A,B,v_b);
    // the same as above for C
    vector<int> v_c;
    addPath(A,C,v_c);
    // n stores the min of both the size of the vector, so that i can traverse both together
    int n = min(v_b.size(), v_c.size());
    // a stores the value of the common ancestor, and for now -1 if there is no common ancestor
    int a = -1;
    // traverse both the vector simultaneously
    for(int i=0;i<n;i++){
        // if both the values of (i)th element same, then resubstitute (a) as that
        if(v_b[i] == v_c[i]){
            a = v_b[i];
        }
        // else break the loop
        else{
            break;
        }
    }
    // return the value fo the least common ancestor
    return a;
}