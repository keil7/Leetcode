//run-time O(N), space O(1)

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
            return;
        //pre-processing
        int index1 = 0;
        int index2 = 0;
        string word;
        while(index2<s.length()) {
            word.clear();
            if(index1!=0)
                s[index1++] = ' ';
            while(s[index2]!=' '&&index2<s.length()) {
                word += s[index2++];
            }
            while(!word.empty()) {
                s[index1++] = word.back();
                word.pop_back();
            }
            while(s[index2]==' '&&index2<s.length()) {
                ++index2;
            }
        }
        s.erase(index1);
        char temp;
        index1=0;
        index2=s.length()-1;
        while(index1<index2) {
            temp = s[index1];
            s[index1] = s[index2];
            s[index2] = temp;
            ++index1;
            --index2;
        }
    }
};

class SolutionOptim {
public:
    void reverseWords(string &s) {
        if(s.empty())
            return;
        //pre-processing
        int index1 = 0;
        int index2 = 0;
        
        while(index2<s.length()) {
            if(index1!=0)
                s[index1++] = ' ';
            int wordStartIndex = index1;
            while(s[index2]!=' '&&index2<s.length()) {
                s[index1++] = s[index2++];
            }
            if(index1!=wordStartIndex)
                reverseWord(s,wordStartIndex,index1-1);
            while(s[index2]==' '&&index2<s.length()) {
                ++index2;
            }
        }
        s.erase(index1);
        reverseWord(s,0,s.length()-1);
    }
    
private:
    void reverseWord(string &s,int index1,int index2) {
        char temp;
        while(index1<index2) {
            temp = s[index1];
            s[index1] = s[index2];
            s[index2] = temp;
            ++index1;
            --index2;
        }
    }
};
