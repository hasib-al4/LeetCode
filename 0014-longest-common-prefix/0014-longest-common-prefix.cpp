class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s={""};
        int n = strs.size();
        int minLength = strs[0].size();
        for(int i = 0; i < n; i++) {
             minLength = min(minLength, (int)strs[i].size());
        }
        for(int i = 0; i < minLength; i++) {
            for(int j = 1; j < n; j++) {
                if(strs[0][i] != strs[j][i]) return s;
            }
            s.push_back(strs[0][i]);
        }
        return s;
    }
};