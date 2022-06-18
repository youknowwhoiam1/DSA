class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(s.size() == 1){
            return x;
        }
        string t = "";
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '0' and t == ""){continue;}
            t += s[i];
        }
        long long p = stoll(t, nullptr, 10);
        if(x < 0){p *= -1;}
        if(p > 2147483641 or p < -2147483648){return 0;}
        return int(p);
    }
};