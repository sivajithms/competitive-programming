#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cap(n, 0);

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(i) cap[i] = cap[i - 1];
        cap[i] -= a;
        cap[i] += b;
    }

    int ans = *max_element(cap.begin(), cap.end());
    
    cout<< ans;
    return 0;
}
