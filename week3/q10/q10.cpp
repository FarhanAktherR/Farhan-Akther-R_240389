class Solution {
public:
// function to find the (k)th permutation of first n natural numbers
    string getPermutation(int n, int k) {
        // num to store first n natural numbers
        vector <int> num;
        // fac to calculate n!
        // then act as the number of permutation possile by fixing first i+1 numbers in loop
        int fac = 1;
        // iterate first n natural numbers
        for(int i=1;i<=n;i++){
            // add i to num
            num.push_back(i);
            // multiply i to fac
            fac *= i;
        }
        // empty string to keep adding the digits
        string s = "";
        // decrease k by 1 so that when i divide it by (n-i-1)!, i get the proper index in num to be added
        k--;
        // run loop n times to add n numbers
        for(int i=0;i<n;i++){
            // fac stores (n-i-1)!
            fac /= n-i;
            // value of x tells me that i am suppsed to make (i)th digit as (x+1)th smallest value in num
            int x = k/fac;
            // add the num[x] to the string, which is the (x+1)th smallest value in num
            s += to_string(num[x]);
            // now remove num[x] from num
            num.erase(num.begin() + x);
            // find the remainder when k is divided by (n-i-1)!, which will give the k to find the next digit
            k %= fac;
        }
        // return the finally string with the (k)th permutation
        return s;
    }
};