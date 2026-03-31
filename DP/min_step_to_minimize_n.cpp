// Given a number N, the task is to count minimum steps to minimize it to 1 according to the following criteria:

// If N is divisible by 2 then you may reduce N to N/2.
// If N is divisible by 3 then you may reduce N to N/3.
// Otherwise, Decrement N by 1.
// Example 1:

// Input: N = 10
// Output: 3
// Explanation: 10 - 1 = 9 / 3 = 3 / 3 = 1

#include <bits/stdc++.h>
using namespace std;

#define inf LLONG_MAX            

vector<long long> dp;

long long helper(long long n) {
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;

    if (dp[n] != -1) return dp[n];

    long long a = helper(n - 1);
    long long b = (n % 2 == 0) ? helper(n / 2) : inf;
    long long c = (n % 3 == 0) ? helper(n / 3) : inf;

    return dp[n] = min({a, b, c}) + 1;
}

int main() {
    long long N = 10;

    dp.resize(10000 + 1, -1);

    cout << helper(N) << endl;

    return 0;
}
