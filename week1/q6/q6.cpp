
class Solution {
  public:
    int maxLength(string& s) {
        // maxlen to store the max length
        // a to keep track of '(' and ')'
        // len to store length temporarily
        int maxlen=0,a=0,len=0;
        // and now I run two loops, one from start to end and the other from end to start
        // in first loop
        // whenever I find '(' a++, and whenever I find ')' a-- and len += 2(as this gives me a valid pair)
        // when I get a balanced string (a=0), i put max(maxlen,len) to max
        // and if ever a<0 ( more ')' than '(' ), i reset a=0 and len=0
        // this helps me prevent the cases in which extra ')' are there
        // but doesn't tackle the case in which '(' is more
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                a++;
            }
            else if(s[i]==')'){
                a--;
                len += 2;
            }
            
            if(a==0){
                maxlen = max(maxlen,len);
            }
            if(a<0){
                a = 0;
                len = 0;
            }
        }
        // reset a=0 and len=0 for second loop
        a = 0,len = 0;
        // now to tackle the case of more '(', we run the second loop backwords
        // when I find '(', a++ and len += 2 (as it confirms a proper pair)
        // when I find ')', a--
        // if I find a balanced string is found (a=0), put maxlen as max(maxlen,len)
        // and if ever '(' is more than ')' (a>0), i reset a=0 and len=0
        // this helps prevent the case in which '(' is more
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                a++;
                len += 2;
            }
            else if(s[i]==')'){
                a--;
            }
            
            if(a==0){
                maxlen = max(maxlen,len);
            }
            if(a>0){
                a = 0;
                len = 0;
            }
        }
        // finally return the value of max length
        return maxlen;
    }
};