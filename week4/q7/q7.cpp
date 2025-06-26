// function to find the next greater element for each element
vector<int> Solution::nextGreater(vector<int> &A) {
    // vector initialised with -1 of same size as A
    vector<int> V(A.size(),-1);
    // multimap to store the values which i am searching for next greatest (using multimap as duplicate values are possible)
    multimap<int,int> M;
    // traverse throught A
    for(int i=0;i<A.size();i++){
        // insert the element with its position to multimap
        M.insert({A[i], i});
        // traverse through multimap while the values are less then A[i] (we got the next greatest element)
        for(auto m = M.begin(); m != M.lower_bound(A[i]); ){
            // replace the -1 in vector V with A[i] in its position in A
            V[m->second] = A[i];
            // remove the element
            m = M.erase(m);
        }
    }
    // return the vector
    return V;
}