#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int ans = 0;

    int totalDring = k * l;
    int totalLime = c * d;

    ans = min({totalDring / nl, totalLime, p / np}) / n;
    cout<< ans << endl;

    return 0;
}
