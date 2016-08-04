class Solution {
public:
    int calculate(string s) {
        if(s.empty())
            return 0;
        int pos = 0;
        int res = 0, sign = 1;
        int num = getNum(s,pos);//pos: input->first digit,output->operator
        while(pos!=string::npos) {
            switch(s[pos]) {
                case '+' :
                    res += (sign*num);
                    sign = 1;
                    num = getNum(s,++pos);
                    break;
                case '-' :
                    res += (sign*num);
                    sign = -1;
                    num = getNum(s,++pos);
                    break;
                case '*' :
                    num *= getNum(s,++pos);
                    break;
                case '/' :
                    num /= getNum(s,++pos);
                    break;
            }
        }
        res += (sign*num);
        return res;
    }
private:
    int getNum(string &s,int &pos){
        pos = s.find_first_not_of(' ',pos);
        int end = s.find_first_not_of("0123456789",pos);
        int num;
        
        if(end!=string::npos){
            num = stoi(s.substr(pos,end-pos));
            pos = s.find_first_of("+-*/",end);
        }
        else {
            num = stoi(s.substr(pos,s.length()-pos));
            pos = string::npos;
        }
        return num;
    }
};
