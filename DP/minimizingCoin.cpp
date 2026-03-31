#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& coin, int sum, int tar) {
    if (sum == tar) return 0;
    if (sum > tar) return INT_MAX;

    int res = INT_MAX;

    for (int i = 0; i < coin.size(); i++) {
        int sub = helper(coin, sum + coin[i], tar);

        if (sub != INT_MAX) {
            res = min(res, 1 + sub);
        }
    }

    return res;
}

int main() {

    int n_coin, tsum;
    cin >> n_coin >> tsum;

    vector<int> coin(n_coin);
    for (int i = 0; i < n_coin; i++) {
        cin >> coin[i];
    }

    cout << helper(coin, 0, tsum);

    return 0;
}
