// Problem URL : https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

// Editorial URL : https://youtu.be/aesQhc-3ero
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        //suffix min
        vector<char> suffix(n);
        suffix[n - 1] = s[n - 1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = min(suffix[i + 1], s[i]);
        }
        
        int idx = 0;
        string t="";
        string res="";
        while(idx < n){
            if(t.empty()){
                t += s[idx];
                idx++;
                continue;
            }
            
            if(suffix[idx] < t.back()){
                char req = suffix[idx];
                
                while(s[idx] != req){
                    t += s[idx];
                    idx++;
                }
                t += s[idx];
                idx++;
               
            }
            
            res += t.back();
            t.pop_back();
        }
        // int x = t.size()-1;
        while(!t.empty() ){
            res += t.back();
            t.pop_back();
        }
        return res;
    }
};
