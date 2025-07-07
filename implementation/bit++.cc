#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;

    while(n--){
        int i = 3;
        char c;
        string s = "";

        while(i--){
            cin >> c;
            s += c;
        }

        if(s.substr(0, 2) == "++" || s.substr(1, 2) == "++") ans++;
        else ans--;
    }

    cout << ans;

    return 0;
}