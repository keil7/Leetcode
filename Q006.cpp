class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        int len = s.length();
        int posConvert = 0;
        string sConvert(len,'0');
        for(int r=0;r<numRows;++r) {
            if(r==0||r==numRows-1) {
                for(int pos=r;pos<len;pos+=(2*numRows-2)) {
                   sConvert[posConvert++] = s[pos];
                } 
            }
            else {
                for(int pos=r;pos<len;pos+=(2*numRows-2*(1+r))) {
                    sConvert[posConvert++] = s[pos];
                    if(pos==r)
                    	continue;
                    pos += 2*r;
                    if(pos<len)
                        sConvert[posConvert++] = s[pos];
                } 
            }
        }
        
        return sConvert;
    }
};
