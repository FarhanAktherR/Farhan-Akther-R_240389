class Solution {
public:
// function to find the number of distinct triplets with sum equal to zero
    vector<vector<int>> threeSum(vector<int>& nums) {
        // first I sort the vector so that it becomes easier to select distinct elments
        sort(nums.begin(),nums.end());
        // n to store the number of numbers;
        int n = nums.size();
        // a 2d vector to store the triplets
        vector<vector<int>> triplets;
        // so im gonna iterate the first element and then use two pinter for the second and third element
        for(int i=0;i<n-2;i++){
            // second element starts from the left of all the terms on the right of i
            int j=i+1;
            // third element starts from the end
            int k=n-1;
            while(j<k){
                // if the sum is zero
                if(nums[i]+nums[j]+nums[k]==0){
                    // add the lements to the 2d vector
                    triplets.push_back({nums[i],nums[j],nums[k]});
                    // move the j forward and k backward (both moving towards centre till they meet)
                    j++;
                    k--;
                    // to skip duplicate elements in j
                    while(j<k && nums[j-1]==nums[j]){
                        j++;
                    }
                    // to skip duplicate lements in k
                    while(j<k && nums[k+1]==nums[k]){
                        k--;
                    }
                }
                // if the sum is less than zero
                else if(nums[i]+nums[j]+nums[k]<0){
                    // we move j forward so that larger values get added to make it zero
                    j++;
                }
                // if the sum is greater than zero
                else{
                    // we move the k backward so that smaller values get added to make the sum zero
                    k--;
                }
                // the above works as for a fixed value of i,
                // there is only one value of sum of j and k so the it becomes zero
                // so one value of j can only pair with one value of k to make it zero
            }
            // to remove the duplicates in i
            while(i<n-2 && nums[i]==nums[i+1]){
                i++;
            }
            // the above works as we had more elements before and even if i consider the next with same value,
            // it will be same or only a subset of the previous case
        }
        return triplets;
    }
};