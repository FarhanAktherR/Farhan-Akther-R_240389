// function to find the number of subarrays with exactly B distinct integers
int Solution::solve(vector<int> &A, int B) {
    // n is the length of A
    int n = A.size();
    // a map to store the frequencies
    map<int,int> m;
    // good keeps track of the number of subarrays with exaclt B distinct integers
    // x to keep track of the number of distinct integers in the window
    int good = 0,x=0;
    // i and j are rwo pointers
    for(int i=0,j=0;i<n-B+1;i++){
        // till the number of distinct integers is equal to B or j = n-1
        while(x<B && j<n){
            // if the number is new
            if(m[A[j]] == 0){
                // increment x
                x++;
            }
            // increment the frequency of the number
            m[A[j]]++;
            // move j forward
            j++;
        }
        // if the number of distinct numbers is B
        if(x==B){
            // increment good for the current subarray
            good++;
            // k is to check how much more I can increase the window,
            // such that the number of distinct elements still remain B
            int k = 0;
            // till a new number is found or till j+k = n-1
            while(m[A[j+k]]>0 && j+k<n){
                // increment good
                good++;
                // move the window forward
                k++;
            }
        }
        // remove the (i)th element as it will be out of the window in next iteration
        m[A[i]]--;
        // if the frequncy of the lement i removed became zero
        if(m[A[i]]==0){
            // decrease x as 1 number is gone
            x--;
        }
    }
    // return the number of good subarrays
    return good;
}