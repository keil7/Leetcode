class Solution {
public:
    string countAndSay(int n) {
        if(n==0)
            return "";
        if(n==1)
            return "1";
        string inStr = countAndSay(n-1);
        string outStr;
        int i = 0;
        int count=1;
        for(;i<inStr.length()-1;++i) {
            if(inStr[i]==inStr[i+1]) {
                count++;
            }
            else {
                outStr = outStr + to_string(count) + inStr[i];
                count = 1;
            }
        }
        
        //last part
        outStr = outStr + to_string(count) + inStr[i];
            
        return outStr;
    }
};
