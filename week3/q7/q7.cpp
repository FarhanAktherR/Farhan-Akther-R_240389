// function to count the occurance of an integer in a sorted array
int Solution::findCount(const vector<int> &A, int B) {
    // n to store the size of the array
    int n = A.size();
    // left to keep track of the start of the active window
    int left = 0;
    // right to keep track of the end of the active window
    int right = n-1;
    // while the active region is not empty
    while(left <= right){
        // mid will be the centre of the active region
        int mid = (left+right)/2;
        // if mid is equal to B
        if(A[mid] == B){
            // i to iterate to the left of mid
            int i = mid;
            // j to iterate to the rigth of mid
            int j = mid;
            // while the value to the left of i is equal to B
            while(A[i-1] == B && i-1 >= 0){
                // move i to the left
                i--;
            }
            // while the value to the right of j is equal to B
            while(A[j+1] == B && j+1 < n){
                // move j to the right
                j++;
            }
            // return j-i+1, which will be the number of occurance of B
            return j-i+1;
        }
        // if value at mid is greater than B
        else if(A[mid] > B){
            // shrink the active region to only the left of mid
            right = mid-1;
        }
        // if value at mid is less than B
        else{
            // shrink the actie region to only the right of mid
            left = mid+1;
        }
    }
    // if no value equal to B was found, return 0
    return 0;
}