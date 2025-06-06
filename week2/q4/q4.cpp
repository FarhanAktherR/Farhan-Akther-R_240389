class Solution {
public:
// function to find all the starting index of p's anagrams
    vector<int> findAnagrams(string s, string p) {
        // n1 stores the length of s and n2 stores the length of p
        int n1 = s.size(), n2 = p.size();
        // v1 and v2 of size 26 to store frequancy of the 26 lower case alphabets
        // v1 stores the frequncy in s
        // v2 sores the frequncy in p
        vector<int> v1(26), v2(26);
        // to store the frequency of each letter in p
        for(int i=0;i<n2;i++){
            // add frequency to the ('letter' - 'a')th index
            v2[p[i]-'a']++;
        }
        // vector to store the starting index of the anagrams
        vector<int> anagram;
        // we only check for anagrams if the length of s is greater than or equal to p
        if(n1>=n2){
            // i and j are two pointers
            for(int i=0,j=0;j<n1;i++,j++){
                // for i=0
                if(i==0){
                    // I move j till the size of the window is equal to the size of p
                    while(j<n2){
                        // increase the frequncy of the letter i found
                        v1[s[j]-'a']++;
                        // move j forward
                        j++;
                    }
                    // just moved j a step backwards as it will be incremented in the next iteration by the for loop
                    j--;
                }
                // for i after 0
                else{
                    // j is moved forward by the for loop
                    // then increment the frequncy of the letter i found
                    v1[s[j]-'a']++;
                }
                // check if frequncies of s and p are same
                if(v1==v2){
                    // add that index
                    anagram.push_back(i);
                }
                // im gonna be moving i forward
                // so remove the frequency of the (i)th element as it will be out of the window in next iteration
                v1[s[i]-'a']--;
            }
        }
        // return the vector with the index of all anagrams
        return anagram;
    }
};