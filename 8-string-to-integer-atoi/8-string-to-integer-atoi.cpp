class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        string t = "";
        int sg = 0, ok = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ' ' and t != ""){
                break;
            }else if(s[i] == ' ' and t == "") {
                if(ok or sg){return 0;}
                continue;
            }else if(s[i] == '0' and t == ""){
                ok = 1;
            }else if(sg != 0 and (s[i] == '-' or s[i] == '+')){
                if(t != ""){break;}
                return 0;
            }else if(s[i] == '-'){
                if(ok){return 0;}
                if(t!=""){break;}
                sg = -1;
            }else if(s[i] == '+'){
                if(ok){return 0;}
                if(t!=""){break;}
                sg = 1;
            }else if((s[i] < 48 or s[i] > 57)){
                break;
            }else{
                ok = 0;
                t += s[i];
            }
        }
        if(t == ""){return 0;}
        if(sg==0){sg=1;}
        int j=0;
        if(t.size() > 10){
            if(sg==-1){
                return -2147483648;
            }else{
                return 2147483647;
            }
        }
        long long k = 0;
        for(int i = t.size()-1;i>=0;i--){
            k += (t[i]-'0')*pow(10,j);j++;
        }
        k *= sg;
        if(k < -2147483648){k = -2147483648;}
        if(k > 2147483647){k = 2147483647;}
        int ans = int(k);
        return ans;
    }
};