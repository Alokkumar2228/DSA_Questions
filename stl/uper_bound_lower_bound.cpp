#include <bits/stdc++.h>
using namespace std;

int main() {
    // for vector pair and we have check with first element in pair
//     vector<pair<int,int>> str = {{0,5},{0,3},{1,7},{2,4}};

// int idx = lower_bound(str.begin(), str.end(), make_pair(1, INT_MIN)) - str.begin();

// cout << idx;

// // for vector

// int idx = lower_bound(str.begin() , str.end() , 3) - str.begin();
// int idx2 = upper_bound(str.begin() , str.end(),3) - str.begin();



// Ques : leetcode 3709

// upper_bond and lower_bond check in vector containing pair;

vector<pair<int,int>>str = {{0,5},{0,3},{1,7},{2,4},{3,8}};

int lwr_idx = lower_bound(str.begin() , str.end() , make_pair(2 , INT_MIN)) - str.begin();
int upper_idx = upper_bound(str.begin() , str.end(),make_pair(2 , INT_MAX)) - str.begin();

cout<<lwr_idx<<endl;
cout<<upper_idx<<endl;
}
//if INT_MAX -> long long me lena hai tho -> LONG_MAX , for INT_MIN -> LONG_MIN;

// how to INT_MAX and INT_MIN in long long

// In C++, INT_MAX and INT_MIN are limits for the int data type (usually 32-bit).
// For long long (usually 64-bit), you should use:

// LLONG_MAX

// LLONG_MIN

// These are defined in the header <climits>.

// Example
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     long long maxVal = LLONG_MAX;
//     long long minVal = LLONG_MIN;

//     cout << "LLONG_MAX = " << maxVal << endl;
//     cout << "LLONG_MIN = " << minVal << endl;

//     return 0;
// }

