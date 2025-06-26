// function to solve arithmetic expression in RPN
int Solution::evalRPN(vector<string> &A) {
    // stack to store the integers
    stack <int> s;
    // traverse through A
    for(auto& x : A){
        // if x is an operator
        if(x=="+" || x=="-" || x=="*" || x=="/"){
            // right will be the last value
            int right = s.top();
            // remove that value
            s.pop();
            // left will be the value before that
            int left = s.top();
            // remove that value also
            s.pop();
            // n to store the result
            int n;
            // do operation according to the operator and store in n with left being before the operator anf right after the operator
            if(x == "+"){
                n = left + right;
            }
            else if(x == "-"){
                n = left - right;
            }
            else if(x == "*"){
                n = left * right;
            }
            else if(x == "/"){
                n = left / right;
            }
            // now add the result n to the end of the stack
            s.push(n);
        }
        // if a string of number
        else{
            // convert the string to integer and add it to the end of the stack
            s.push(stoi(x));
        }
    }
    // return the last of the stack, which will be the result
    return s.top();
}