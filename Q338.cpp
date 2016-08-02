class Solution {
public:
    vector<int> countBits(int num) {
        if(num<0)
            return {};
        if(num==0)
            return{0};
        
        vector<int> r = {0,1};
        for(int i=2;i<=num;++i) {
            if(!(i&1))//even
                r.push_back(r[i>>1]);
            else//odd
                r.push_back(r[i-1]+1);
        }
        return r;
    }
};
