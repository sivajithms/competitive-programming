#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int mini = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] <= arr[mini]) mini = i;
        if(arr[i] > arr[maxi]) maxi = i;
    }

    int add = maxi > mini ? -1 : 0;

    cout<< maxi + (n - 1 - mini) + add;

    return 0;
}