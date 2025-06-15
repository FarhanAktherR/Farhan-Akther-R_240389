// function to find (x^n)%d
int Solution::pow(int x, int n, int d) {
    // if n=0, then x^n will be 1
    if(n == 0){
        // so return 1%d
        return 1 % d;
    }
    // mod to keep track of %d when multiplied
    long mod = 1;
    // new_x stores x%d, and then later will store the remainder of its square
    long new_x = x % d;
    // if remiander is negative
    if(new_x < 0){
        // make the remainder positive
        new_x += d;
    }
    // (xy)%d will be same as ((x%d)*(y%d))%d
    // so we keep updating new_x with remiander of its square
    // so by i loops, x_new will store the value of (x^(2^i))%d
    // and whenever n is odd, we add its contribution to mod
    // while n is positive
    while(n>0){
        // if n is odd
        if(n%2 == 1){
            // replace mod with remiander of mod*new_x
            mod = (mod * new_x) % d;
        }
        // update the new_x with the remainder of its square
        new_x = (new_x * new_x) % d;
        // half n
        n = n/2;
    }
    return mod;
}