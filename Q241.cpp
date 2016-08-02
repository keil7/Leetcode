class Solution {

public:
    vector<int> diffWaysToCompute(string input) {
        if(input.empty())  return {};
        //Memoization,top-down
        //vector<vector<vector<int>>> matrix(input.length(),vector<vector<int>>(input.length()));
        //vector<int> result = helper(input,0,input.size()-1,matrix);
        
        //tablutation,buttom-up
        vector<int> result = helperDP(input);
        sort(result.begin(),result.end());
        return result;
    }
    
private:
    vector<int> helper(const string& input, const int begin, const int end, vector<vector<vector<int>>>& memo) {
        if(begin>end) return {};
        if(!memo[begin][end].empty()) return memo[begin][end];
        
        vector<int> v;
        for(int i=begin;i<=end;++i) {
            if(input[i]!='+'&&input[i]!='-'&&input[i]!='*')
                continue;
            vector<int> rightPart = helper(input,begin,i-1,memo);
            vector<int> leftPart = helper(input,i+1,end,memo);
            
            for(int j=0;j<rightPart.size();++j) {
                for(int k=0;k<leftPart.size();++k) {
                    switch(input[i]) {
                        case '+': v.push_back(rightPart[j]+leftPart[k]);break;
                        case '-': v.push_back(rightPart[j]-leftPart[k]);break;
                        case '*': v.push_back(rightPart[j]*leftPart[k]);break;
                        default: break;
                    }
                }
            }
        }
        if(v.empty())
            v.push_back(stoi(input.substr(begin,end-begin+1)));
        memo[begin][end] = v;
        return v;
    }
    
    vector<int> helperDP(const string& input) {
        vector<int> num;
        vector<char> op;
        for(int i=0,s=0;i<input.length();++i){
            if(isdigit(input[i])) continue;
            
            op.push_back(input[i]);
            num.push_back(stoi(input.substr(s,i-s)));
            s = i+1;
       }
       
       vector<vector<vector<int>>> table(num.size(),vector<vector<int>>(num.size()));
       for(int begin=0;begin<num.size();++begin) {
           table[begin][begin] = num[begin];
       }
       
       for(int dist=1;dist<num.size();++dist) {
           for(int begin=0;begin<num.size()-dist;++begin) {
               for(int i=0;i<dist;++i) {
                    swtich(op[i]) {
                        case '+':
                            for(auto left : table[begin][begin+i])
                                for(auto right : table[begin+i+1][begin+dist])
                                    table[begin][begin+dist].push_back(table[left+right]);
                            break;
                        case '-':
                            for(auto left : table[begin][begin+i])
                                for(auto right : table[begin+i+1][begin+dist])
                                    table[begin][begin+dist].push_back(table[left-right]);
                            break;
                        case '*': 
                            for(auto left : table[begin][begin+i])
                                for(auto right : table[begin+i+1][begin+dist])
                                    table[begin][begin+dist].push_back(table[left*right]);
                            break;
                        default: break; 
                    }
              }
          }
       }
       
       return table[0][num.size()-1];
    }
};
