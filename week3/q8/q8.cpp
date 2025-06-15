// function to find the Bth smallest element in an unsorted array
int Solution::kthsmallest(const vector<int> &A, int B) {
    // n to store the size of the array
    int n = A.size();
    // left an right to store the min and max values, which will be the start and end of the active region
    int left = A[0], right = A[0];
    // itertate the array from i=1 to i=n-1
    for(int i=1;i<n;i++){
        // replace left with the min of left and A[i]
        left = min(left,A[i]);
        // replace right with the max of right and A[i]
        right = max(right,A[i]);
    }
    // while the active region is not empty
    while(left <= right){
        // mid will be the middile of the active region
        int mid = (left+right)/2;
        // x to keep track of how many elements are less than or equal to mid
        int x = 0;
        // iterate over the array
        for(int i=0;i<n;i++){
            // if (i)th element is less than or equal to mid
            if(A[i] <= mid){
                // increment x
                x++;
            }
        }
        // if x is less than B
        if(x<B){
            // make the active region to the right of mid
            left = mid + 1;
        }
        // if x is greater than or equal to B
        else{
            // make the active region to the left of mid
            // as it is possible that there might be an even smaller value, that still has x>=B
            right = mid - 1;
        }
    }
    // (basically we want the min value in the range of left to right, that has x>=B, x>B when there is duplicate values)
    // when the above loop ends, left will be the smallest value with x>=B
    // so we return left
    return left;
}