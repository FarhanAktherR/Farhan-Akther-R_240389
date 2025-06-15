// function to return all subsets sorted lexicographically and the elements in subsets be in non-descending order
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    // first i sort the given array
    sort(A.begin(), A.end());
    // now i create a set of vector to store the vectors
    // as it weill be arranged lexicographically with no duplicates
    set <vector<int>> S = {{}};
    // iterate over A
    for(auto& a : A){
        // created a temporary 2d vector as to iterate S, while being able to update S
        vector<vector<int>> temp(S.begin(), S.end());
        // iterate over temp
        for(auto& s : temp){
            // temp vector to store the current vector
            vector <int> temp1 = s;
            // add the current element (a) to the current vector
            temp1.push_back(a);
            // now add the updated vector back to S
            S.insert(temp1);
        }
    }
    // now convert the set of vector to a 2d vector
    vector <vector<int>> V(S.begin(),S.end());
    // return the 2d vector with subarrays
    return V;
}