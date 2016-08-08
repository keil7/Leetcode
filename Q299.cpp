class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.empty()||guess.empty())
            return "0A0B";
            
        vector<int> r(10,INT_MIN);
        int bull = 0;
        for(int i=0;i<secret.length();++i) {
            if(secret[i]==guess[i])
                bull++;
            else {
                r[secret[i]-'0'] = r[secret[i]-'0']==INT_MIN ? 1:r[secret[i]-'0']+1;
                r[guess[i]-'0'] = r[guess[i]-'0']==INT_MIN ? -1:r[guess[i]-'0']-1;
            }
        }
        int left = 0;
        for(int i=0;i<10;i++) {
            if(r[i]>0)
                left += r[i];
        }
        
        return to_string(bull)+"A"+to_string(secret.length()-bull-left)+"B";
    }
};
