// function to find the number of subarrays with sum less than B
int Solution::solve(vector<int> &A, int B) {
    // n stores the size of A
    int n = A.size();
    // sum to keep track of the sum
    // good keeps track of the number of subarrays with sum less than B
    int sum = 0,good = 0;
    // i and j are pointers
    for(int i=0,j=0;i<n;i++){
        // till the sum is maximum and less than B or j = n-1
        while(sum+A[j]<B && j<n){
            // add the current value to the sum
            sum += A[j];
            // move j forward, increasing the size of the window
            j++;
        }
        // the number of subarrays with the (i)the lement included will be j-i
        // and all of them will have sum less than B as they will be smaller than or equal to the size of the window
        good += j-i;
        // remove the (i)th element as it will be out of the window in next iteration
        sum -= A[i];
    }
    // return the number of good subarrays
    return good;
}