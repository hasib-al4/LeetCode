class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = b.size();
        string s = a;
        int cnt = 1;
        while(s.size() < n) {
            s += a;
            cnt++;
        }
        if(s.find(b) != string::npos) return cnt;
        s+=a;
        cnt++;
        if(s.find(b) != string::npos) return cnt;
        return -1;



    }
};