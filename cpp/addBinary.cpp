// link = https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        // keep a to be largest of two... logic help
        if(b.size() > a.size()){
            string tmp = a;
            a = b;
            b = tmp;
        }
        
        int N = a.size();
        int M = b.size();
        
        for(int offset = 1; offset <= M; ++offset){
            // if we are adding two 1's we have to carry
            if(a[N-offset] == '1' && b[M-offset] == '1'){
                a[N-offset] = '0';
                // now start chaining the carry if we have to
                int chain = 1;
                while(1){
                    if(N-offset-chain < 0) { a.insert(a.begin(), '1'); ++N; break; }
                    else if(a[N-offset-chain] == '1'){
                        a[N-offset-chain] = '0';
                        ++chain;
                    }else{
                        a[N-offset-chain] = '1';
                        break;
                    }
                }// end while
            }// end if
            // if we are adding a 1 to a 0
            else if(a[N-offset] == '0' && b[M-offset] == '1')
                a[N-offset] = '1';
            // if we are adding a 0 to a 1... nothing happens
            // if we are adding a 0 to a 0... nothing happens
        }// end for
        return a;
    }// end addBinary()
};
