#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        string num;
        cin >> num;
        vector<string> ans;

        for(int i = num.size() - 1; i >= 0; i--){
            int val = num[i] - '0';
            if(val){
                string part = to_string(val);
                part += string(num.size() - 1 - i, '0');
                ans.push_back(part);
            }
        }

        cout<< ans.size()<<endl;
        for(string s : ans) cout<< s << " ";
        cout<< endl;
    }
    return 0;
}
