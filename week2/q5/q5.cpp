class Solution {
public:
// function to sort the colours in-place
    void sortColors(vector<int>& nums) {
        // a vector of size 3
        // to store the frequncies of 0, 1 and 2
        vector<int> v(3);
        // n is the lenght of the nums
        int n = nums.size();
        // to find the frequncies of 0, 1 and 2
        for(int i=0;i<n;i++){
            // increment the frequncy of the (number)th position
            v[nums[i]]++;
        }
        // i is the pointer to keep track in nums
        int i=0;
        // j is to keep track of 0, 1 and 2
        for(int j=0;j<3;j++){
            // while the frequency of j is greater than 0
            while(v[j]>0){
                // (i)th element of nums as j
                nums[i]=j;
                // decrement the frequency of j
                v[j]--;
                // move i forward
                i++;
            }
        }
    }
};