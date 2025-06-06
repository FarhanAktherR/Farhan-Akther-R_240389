// function to find the length of the langest subarray with sum k
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // n is the number of numbers in the vector 'a'
    int n = a.size();
    // i and j are two iterators and max is for storing the max length of th subarray
    int i = 0,j = 0,max=0;
    // sum to keep track of the sum
    long long sum = 0;
    for(i=0;j<n;i++){
        // when the 'i' (basically the left pointer) moves to right, subtract the previous term from the sum
        if(i!=0){
            sum -= a[i-1];
        }
        // keep adding the terms till the sum is equal to sum and is of max length, or when j = n-1 
        while(sum+a[j]<=k && j<n){
            sum += a[j];
            j++;
        }
        // and if the sum manages to reach k, and if the number of elements are greater than max, replace the max with that
        if(sum==k && j-i+1>max){
            max = j-i;
        }
    }
    // return the max value
    return max;
}