void toBinary(int n) {
    if(n == 0){
        cout << 0;
        return;
    }
    string ans = "";
    while(n != 0){
        if(n % 2 == 1) ans += '1';
        else ans += '0';
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}





int binaryToDecimal(string &b) {
        int n = b.size();
        int ans = 0;
        int p2 = 1;
        for(int i = n-1; i >= 0; i--){
            if(b[i] == '1'){
                ans = ans + p2;
            }
            p2 = p2 * 2;
        }
        return ans;
    }
