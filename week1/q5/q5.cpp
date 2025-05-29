
class Solution {
  public:
    bool isBalanced(string& s) {
        // a checks for '(' and ')'
        // b checks for '{' and '}'
        // c checks for '[' and ']'
        int a=0,b=0,c=0;
        for(int i=0;i<s.size();i++){
            // if it is '(', a++ and if next element exsist, it should not be '}' or ']'
            // if next is '}' or ']' return false
            if(s[i]=='('){
                a++;
                if((i+1<s.size())&&(s[i+1]=='}'||s[i+1]==']')){
                    return 0;
                }
            }
            // if it is ')', a--
            else if(s[i]==')'){
                a--;
            }
            // if it is '{', b++ and if next element exsist, it should not be ')' or ']'
            // if next is ')' or ']' return false
            else if(s[i]=='{'){
                b++;
                if((i+1<s.size())&&(s[i+1]==')'||s[i+1]==']')){
                    return 0;
                }
            }
            // if it is '}', a--
            else if(s[i]=='}'){
                b--;
            }
            // if it is '[', c++ and if next element exsist, it should not be '}' or ')'
            // if next is '}' or ')' return false
            else if(s[i]=='['){
                c++;
                if((i+1<s.size())&&(s[i+1]=='}'||s[i+1]==')')){
                    return 0;
                }
            }
            // if it is ']', a--
            else if(s[i]==']'){
                c--;
            }
            if(a<0||b<0||c<0){
                return false;
            }
        }
        // if by the end of the loop, if either of a,b or c is not zero
        // means they don't have proper opening and closing pair
        // so return false
        if(a!=0||b!=0||c!=0){
            return false;
        }
        // if everthing is satisfied, return true
        return true;
    }
};