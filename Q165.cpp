class Solution {
public:
    int compareVersion(string version1, string version2) {
           int start1 = 0, end1 = 0;
           int start2 = 0, end2 = 0;
           
           while(1) {
                end1 = version1.find('.',start1);
                end2 = version2.find('.',start2);
                
                int num1 = stoi(version1.substr(start1,end1==string::npos?version1.length()-start1:end1-start1+1));
                int num2 = stoi(version2.substr(start2,end2==string::npos?version2.length()-start2:end2-start2+1));
                start1 = end1+1;
                start2 = end2+1;
                
                if(num1>num2) return 1;
                if(num1<num2) return -1;
                if(end1==string::npos&&end2==string::npos) return 0;//[1.1] [1.1]
                else if(end1==string::npos) {
                    while(1) {
                        end2 = version2.find('.',start2);
                        num2 = stoi(version2.substr(start2,end2==string::npos?version2.length()-start2:end2-start2+1));
                        if(num2>0) return -1; //[1] [1.1]
                        if(end2==string::npos) return 0;//[1] [1.0]
                        start2 = end2+1;
                    }
                }
                else if(end2==string::npos) {
                    while(1) {
                        end1 = version1.find('.',start1);
                        num1 = stoi(version1.substr(start1,end1==string::npos?version1.length()-start1:end1-start1+1));
                        if(num1>0) return 1; //[1.1] [1]
                        if(end1==string::npos) return 0;//[1.0] [1]
                        start1 = end1+1;
                    }
                }
                
       }
    }
};
