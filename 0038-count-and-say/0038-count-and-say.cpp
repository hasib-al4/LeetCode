class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = countAndSay(n - 1);
        string result = "";
        int count = 1;
        int m = prev.size();
        for(int i = 1; i < m; i++ ) {
            if(prev[i] == prev[i - 1]) count++;
            else {
                result += to_string(count) + prev[i - 1];
                count = 1;
            }
            
        }
        result += to_string(count) + prev.back();
        return result;

    }
};