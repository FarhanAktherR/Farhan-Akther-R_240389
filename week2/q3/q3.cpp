class Solution {
public:
// function to find the length of the longest substring with no duplicates
    int lengthOfLongestSubstring(string s) {
        // n store the number of characters
        int n = s.size();
        // a vector with size 128 (so that i can store all the characters with ascii value from 0 to 127)
        vector<int> v(128);
        // l to store the current length and max to store the max length
        int l=0,max=0;
        // j is the second pointer
        int j=0;
        for(int i=0;i<n;i++){
            // while the frequency of the element at j is zero
            while(v[s[j]]==0 && j<n){
                // increase the frequncy of the charcters I found
                v[s[j]]++;
                // keep moving j forward
                j++;
                // also increase l to keep track of the length
                l++;
            }
            // if l is greater than max
            if(l>max){
                // make max equal to l
                max = l;
            }
            // as im gonna move i forward, I subtract the frequency of the current (i)th element
            v[s[i]]--;
            // also decrease l as im gonna move i forward
            l--;
        }
        // return max length
        return max;
    }
};