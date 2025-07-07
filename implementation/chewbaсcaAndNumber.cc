#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, ans = 0;
    cin >> n;

    string num = to_string(n); 
    int size = num.size();

    for(int i = 0; i < size; i++) {
        int digit = num[i] - '0';
        int complement = 9 - digit;

        if(i == 0 && digit == 9) continue;
        if(complement < digit) num[i] = complement + '0';
    }

    cout << num << endl;
    return 0;
}
