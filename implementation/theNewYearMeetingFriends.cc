#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> arr = {a, b, c};
    sort(arr.begin(), arr.end());
    int mid = arr[1];

    int ans = abs(a - mid) + abs(b - mid) + abs(c - mid);

    cout << ans << endl;
    return 0;
}
