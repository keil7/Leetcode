class Solution {
public:
    bool isValid(string s) {
        if(s.length()&1)
            return false;
            
        stack<char> stack1;
        for(auto c : s) {
            if(c=='('||c=='{'||c=='[')
                stack1.push(c);
            else {
                if(stack1.empty())
                    return false;
                else if(stack1.top()=='('&&c!=')')
                    return false;
                else if(stack1.top()=='{'&&c!='}')
                    return false;
                else if(stack1.top()=='['&&c!=']')
                    return false;
                else
                    stack1.pop();
            }
        }
        if(stack1.empty())
            return true;
        else
            return false;
    }
};
