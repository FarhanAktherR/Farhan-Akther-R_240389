// vector to work as stack
vector<int> s;
// same as above, but to store the current min
vector<int> s_min;
// to create a stack
MinStack::MinStack() {
    // as the both the above vector are global
    // clear both of them when called again
    s.clear();
    s_min.clear();
}
// to push into stack
void MinStack::push(int x) {
    // add current element to the stack
    s.push_back(x);
    // if x is less than the last element added to the s_min, then add x to s_min
    if(s_min.empty() || x <= s_min.back()){
        s_min.push_back(x);
    }
}
// to remove the last element in the stack
void MinStack::pop() {
    // if empty, don't do anything
    if(s.empty()){
        return;
    }
    // if the element also present in s_min
    if(s.back() == s_min.back()){
        // remove it from s_min also
        s_min.pop_back();
    }
    // remove from s
    s.pop_back();
}
// return the last element from the stack
int MinStack::top() {
    // if s is empty, return -1
    if(s.empty()){
        return -1;
    }
    // return the last element of s
    return s.back();
}
// return the minimum of the stack
int MinStack::getMin() {
    // if s_min is empty, return -1
    if(s_min.empty()){
        return -1;
    }
    // return the last element of s_min
    return s_min.back();
}