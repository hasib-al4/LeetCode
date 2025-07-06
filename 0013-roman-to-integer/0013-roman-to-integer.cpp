class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s.substr(i, 2) != "IV" && s.substr(i, 2) != "IX" &&
                s.substr(i, 2) != "XL" && s.substr(i, 2) != "XC" &&
                s.substr(i, 2) != "CD" && s.substr(i, 2) != "CM") {
                if (s[i] == 'I')
                    num += 1;
                else if (s[i] == 'V')
                    num += 5;
                else if (s[i] == 'X')
                    num += 10;
                else if (s[i] == 'L')
                    num += 50;
                else if (s[i] == 'C')
                    num += 100;
                else if (s[i] == 'D')
                    num += 500;
                else if (s[i] == 'M')
                    num += 1000;
            }

            else {
                if (s.substr(i, 2) == "IV")
                    num += -1;
                else if (s.substr(i, 2) == "IX")
                    num += -1;
                else if (s.substr(i, 2) == "XL")
                    num += -10;
                else if (s.substr(i, 2) == "XC")
                    num += -10;
                else if (s.substr(i, 2) == "CD")
                    num += -100;
                else if (s.substr(i, 2) == "CM")
                    num += -100;
            }
        }
        return num;
    }
};