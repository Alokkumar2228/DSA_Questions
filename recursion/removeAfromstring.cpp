#include <bits/stdc++.h>
using namespace std;

string removechar(string ans, string org) {
    if (org.length() == 0) return ans;

    char ch = org[0];

    if (ch == 'a')
        return removechar(ans, org.substr(1)); // add return here
    else
        return removechar(ans + ch, org.substr(1)); // add return here
}

int main() {
    string org = "alokalnaffd";
    cout << removechar("", org); // output: loklnffd
    return 0;
}
