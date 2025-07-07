#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        ans[nums[i] - 1] = i + 1;
    }

    for(int num : ans) cout<< num << " ";

    return 0;
}